// Problem

// A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
// Each node of the graph is labelled with a distinct integer in the range O to V-1.
// A node is a terminal node if there are no outgoing edges. 
// A node is a safe node if EVERY possible path starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph.
// The answer should be sorted in ascending order.

// Approach

// Reverse all the edges
// Perform topological sort 
// The nodes which comes in the topoSort are safe nodes
// The rest nodes are unsafe as all the paths do not end up at terminal nodes

#include<bits/stdc++.h>

using namespace std;

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>graph(v), revGraph(v);
    vector<int>indegree(v, 0);

    for(int i = 0, u, w; i < e; i++){
        cin>>u>>w;

        graph[u].push_back(w);
        revGraph[w].push_back(u);
        indegree[u]++;
    }

    vector<int>vis(v, 0);
    queue<int>q;
    
    vector<int>ans;
    
    for(int i = 0; i < v; i++){
        if (indegree[i] == 0){
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto it : revGraph[x]){
            indegree[it]--;
            if (indegree[it] == 0){
                q.push(it);
                vis[it] = 1;
                ans.push_back(it);
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(auto it : ans) cout<<it<<" ";
}

// Sample Test Case
// 7 7 
// 0 1
// 0 2
// 1 2
// 1 3
// 3 0
// 4 5
// 2 5

// 12 13
// 0 1
// 8 1
// 8 9
// 9 10
// 10 8
// 11 9
// 1 2
// 2 3
// 3 4
// 3 5
// 5 6
// 4 6
// 6 7

// Output
// 2 4 5 6
// 0 1 2 3 4 5 6 7