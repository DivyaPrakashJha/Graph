// Strongly Connected Components (Kosaraju's Algorithm)

// In a strongly connected component every pair of vertices is reachable to each other 
// Only valid for directed graphs
// Single node is always a SCC

// 1. Sort all the nodes according to the finishing time
// 2. Reverse the graph
// 3. Do a dfs

#include<bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>>&g, vector<int>&visited, stack<int>&s){
    visited[v] = 1;

    for(auto it : g[v]){
        if (!visited[it]){
            dfs(it, g, visited, s);
        }
    }

    s.push(v);
}

void dfs1(int v, vector<vector<int>>&g, vector<int>&visited, vector<int>&temp){
    visited[v] = 1;

    temp.push_back(v);

    for(auto it : g[v]){
        if (!visited[it]){
            dfs1(it, g, visited, temp);
        }
    }

}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>graph(n+1);
    for(int i = 0, u, v; i < m; i++){
        cin>>u>>v;

        graph[u].push_back(v);
    }

    // Sort the nodes according to the finishing time
    stack<int>nodesSortedByFinishingTime;

    vector<int>visited(n+1, 0);

    for(int i = 0; i < n; i++){
        if (!visited[i]){
            dfs(i, graph, visited,nodesSortedByFinishingTime);
        }
    }
    // Reversing the edges of the graph
    vector<vector<int>>revGraph(n+1);
    for(int i = 0; i < n; i++){
        
        visited[i] = 0; // Resetting the visited array for use in the next step

        for(auto it: graph[i]){
            revGraph[it].push_back(i);
        }
    }

    // // Performing a dfs to get the strongly connected components
    int cntSCC = 0;

    vector<vector<int>>SCCs; // For storing the strongly connected components

    while(!nodesSortedByFinishingTime.empty()){
        int x = nodesSortedByFinishingTime.top();
        nodesSortedByFinishingTime.pop();

        if (!visited[x]){
            vector<int>temp;
            cntSCC++;
            dfs1(x, revGraph, visited, temp);

            SCCs.push_back(temp);
        }
    }

    cout<<cntSCC<<endl;

    for(auto it: SCCs){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}

// T.C. - O(V+E)
// S.C. - O(V+E)

// Sample Test Case

// 8 9
// 0 1
// 1 2
// 2 0
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 5

// Output

// 4
