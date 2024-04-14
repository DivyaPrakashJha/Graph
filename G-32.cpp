// Problem

// You are given a weighted undirected graph having n vertices and m edges, describing there are edges between a to b with some weight,
// find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1 .

// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include<bits/stdc++.h>

using namespace std;

#define inf 1e8
#define pii pair<int, int>

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pii>>g(n+1);

    for(int i = 0, u, v, w; i < m; i++){
        cin>>u>>v>>w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int>dist(n+1, inf);
    vector<int>from(n+1, -1);

    int src = 1;
    dist[src] = 0;

    // Dijkstra
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;

        pq.pop();

        for(auto it : g[node]){
            if (dist[it.first] > dis + it.second){
                dist[it.first] = dis + it.second;
                pq.push({dis + it.second, it.first});
                from[it.first] = node;
            }
        }
    }

    if (dist[n] == inf) cout<<-1;
    else{
        vector<int>path;
    
        int j = n;
        while(j != -1){
            path.push_back(j);
            j = from[j];
        }

        reverse(path.begin(), path.end());

        cout<<dist[n]<<endl;
        for(auto it : path) cout<<it<<" ";
    }    
}

// Sample Test Case
// 5 6
// 1 2 2
// 2 5 5
// 2 3 4
// 1 4 1
// 4 3 3
// 3 5 1

// Output
// 5
// 1 4 3 5