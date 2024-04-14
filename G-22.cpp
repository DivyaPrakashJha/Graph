// Problem

// There are a total of N tasks, labeled from 0 to N-1.
// Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: (0, 1)
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

// Approach

// The problem can be expressed in the form of a directed graph
// Clearly if a cycle exists in the graph, then it is not possible to finish all the tasks
// We can simply detect whether a cycle is present or not in the graph
// Or we can use the topological sorting approach to see if we can generate a linear ordering of length n or not

// Using dfs to detect a cycle in a directed graph


#include<bits/stdc++.h>

using namespace std;

bool dfs(int v, vector<vector<int>>&g, vector<int>&vis){
    vis[v] = 2; // Visited and pathvisited

    for(auto it : g[v]){
        if (!vis[it]){
            if (dfs(it, g, vis) == true) return true;
        }
        else if (vis[it] == 2){
            return true;
        }
    }

    vis[v] = 1; // Visited but not pathvisited
    return false;
}

int main(){
    int n, m; // m -> no of pairs
    cin>>n>>m;

    vector<vector<int>>g(n);

    for(int i = 0, u, v; i < m; i++){
        cin>>v>>u;
        
        g[u].push_back(v); // To do task v we have to first complete task u, i.e. directed edge from u to v
    }

    vector<int>vis(n, 0);
    // We will not use the pathVisited vector here, we will do it's job in the vis vector (by marking pathVis as 2)

    for(int i = 0; i < n; i++){
        if (!vis[i]){
            if (dfs(i, g, vis) == true){
                cout<<"No"; // Since cycle is present, hence it is not possible to finish all the tasks
                return 0;
            }
        }
    }

    cout<<"Yes";
}

// Sample Test Case
// 8 11
// 0 2
// 1 0
// 1 2
// 3 1
// 3 4
// 2 4
// 5 4
// 3 5
// 7 5
// 6 7
// 6 3

// 8 11
// 0 2
// 1 0
// 2 1
// 3 1
// 3 4
// 2 4
// 5 4
// 3 5
// 7 5
// 6 7
// 6 3

// Output
// Yes
// No