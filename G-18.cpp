// Problem

// A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
// Each node of the graph is labelled with a distinct integer in the range O to V-1.
// A node is a terminal node if there are no outgoing edges. 
// A node is a safe node if EVERY possible path starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph.
// The answer should be sorted in ascending order.

// Observation : 
// Any node who is a part of a cycle is not a safe node
// Any node which leads to a cycle is not a safe node

#include<bits/stdc++.h>

using namespace std;

bool dfs(int v, vector<vector<int>>&graph, vector<int>&vis){
    vis[v] = 2; // visited and path-visited

    for(auto it : graph[v]){
        if (!vis[it]){
            if (dfs(it, graph, vis) == false) return false;
        }
        else if (vis[it] == 2) return false; // part of cycle i.e not a safe node 
    }

    vis[v] = 1;
    return true;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>graph(v);
    
    for(int i = 0, u, w; i < v; i++){
        cin>>u>>w;

        graph[u].push_back(w);
    }

    vector<int>vis(v, 0); // 1 for visited, 2 for path visited
    for(int i = 0; i < v; i++){
        if (!vis[i]){
            dfs(i, graph, vis);
        }
    }

    for(int i = 0; i < v; i++){
        if (vis[i] == 1) cout<<i<<" "; 
    }
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
