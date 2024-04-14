// Problem

// You are in a city that consists of n intersections numbered from 0 to n-1 with bi-directional roads between some intersections. 
// The inputs are generated such that you can reach any intersection from any other intersection 
// and that there is at most one road between any two intersections.
// You are given an integer n and a 2D integer array roads where roads[i] = [u_i, v_i, time_i] 
// means that there is a road between intersections u_i and v_i that takes time_i minutes to travel. 
// You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
// Return the number of ways you can arrive at your destination in the shortest amount of time. 
// Since the answer may be large, return it modulo 1e9+7.

// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

#include<bits/stdc++.h>

using namespace std;

#define inf LLONG_MAX
#define int long long

signed main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>>g(n);

    for(int i = 0, u, v, w; i < m; i++){
        cin>>u>>v>>w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int>ways(n, 0);
    vector<int>time(n, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq; // {time, node}
    pq.push({0, 0});
    ways[0] = 1;
    time[0] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int t = pq.top().first;

        cout<<node<<" "<<t<<" "<<ways[node]<<endl;

        pq.pop();

        for(auto it : g[node]){
            if (t + it.second < time[it.first]){ // First time reached with min time
                time[it.first] = t + it.second;
                ways[it.first] = ways[node];

                pq.push({t+it.second, it.first});
            }
            else if (t + it.second == time[it.first]){
                ways[it.first] += ways[node] % (int)(1e9+7);
            }
        }
    }

    cout<<ways[n-1]%(int)(1e9+7);

}

// Sample Test Cases

// 7 10
// 0 6 7
// 0 1 2
// 1 2 3
// 1 3 3
// 6 3 3
// 3 5 1
// 6 5 1
// 2 5 1
// 0 4 5
// 4 6 2

// 6 8
// 0 5 8
// 0 2 2
// 0 1 1
// 1 3 3
// 1 2 3
// 2 5 6
// 3 4 2
// 4 5 2

// 6 8
// 0 1 1000000000
// 0 3 1000000000
// 1 3 1000000000
// 1 2 1000000000
// 1 5 1000000000
// 3 4 1000000000
// 4 5 1000000000
// 2 5 1000000000

// Output
// 4
// 3
// 1