// Problem

// There are n cities and m edges connected by some number Of flights.
// You are given an array flights where flights[i] = [from_i, to_i, price_i] 
// indicates that there is a flight from city from_i to city to_i with cost price_i.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
// If there is no such route, return -1.

// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>>g(n+1);
    for(int i = 0, u, v, w; i < m; i++){
        cin>>u>>v>>w;

        g[u].push_back({v, w});
    }

    vector<int>distance(n+1, inf);
    queue<vector<int>>q; // {Stops, node, dist}

    int src, dst, k;
    cin>>src>>dst>>k;

    q.push({0, src, 0});
    distance[src] = 0;

    while(!q.empty()){
        int stops = q.front()[0];
        int node = q.front()[1];
        int dist = q.front()[2];

        q.pop();
        if (stops > k or node == dst) continue; // We can have the (k+1)th stop at max as the destination

        for(auto it : g[node]){
            if (distance[it.first] > dist + it.second){
                q.push({stops+1, it.first, dist+it.second});
                
                distance[it.first] = dist + it.second;
            }
        }
    }

    if (distance[dst] == inf) cout<<-1;
    else cout<<distance[dst];
}


// Sample Test Case

// 5 6
// 0 1 5
// 0 3 2
// 3 1 2
// 1 2 5
// 1 4 1
// 4 2 1
// 0
// 2 
// 2

// Output
// 7