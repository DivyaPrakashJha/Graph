// Problem

// There are n cities labeled from 0 to n-1 with m edges connecting them.
// Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, 
// and given the integer distanceThreshold. 
// You need to find out a city with the smallest number of cities that are reachable through some path 
// and whose distance is at most Threshold Distance. If there are multiple such cities, our answer will be the city with the greatest label.

// Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.

// https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>edges(m, vector<int>(3)); // (u --w-- v)
    for(auto &v : edges){
        cin>>v[0]>>v[1]>>v[2];
    }

    int distanceThreshold;
    cin>>distanceThreshold;

    vector<vector<int>>cost(n, vector<int>(n, inf));
    for(int i = 0; i < n; i++) cost[i][i] = 0;

    for(auto it : edges){
        cost[it[0]][it[1]] = it[2];
        cost[it[1]][it[0]] = it[2];
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    int ans = 0, mnCount = inf;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if (cost[i][j] <= distanceThreshold){
                cnt++;
            }
        }

        if (cnt <= mnCount) ans = i;
        mnCount = min(mnCount, cnt);
    }

    cout<<ans<<" "<<mnCount-1;
}

// Input

// 4 4
// 0 1 3
// 1 2 1
// 1 3 4
// 2 3 1
// 4

// 5 6
// 0 1 2
// 0 4 8
// 1 2 3
// 1 4 2
// 2 3 1
// 3 4 1
// 2

// Output

// 3 2
// 0 1
