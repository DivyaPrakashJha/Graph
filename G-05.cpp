// Problem

// Given an undirected graph with V vertices. 
// We say two vertices u and v belong to a single province if there is a path from u to v or v to u.
// Your task is to find the number of provinces.
// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.


#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>>&g, vector<int>&visited){
    visited[v] = 1;

    for(auto it : g[v]){
        if (!visited[it]){
            dfs(it, g, visited);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>g(n+1);
    for(int i = 0, u, v; i < m; i++){
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    vector<int>visited(n+1, 0);

    for(int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt++;
            dfs(i, g, visited);
        }
    }

    cout<<cnt;
}


// Sample Test Case
// 4 2
// 1 2
// 3 4

// Output
// 2