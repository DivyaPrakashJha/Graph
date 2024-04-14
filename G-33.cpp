// Problem

// Given a n * m matrix grid where each element can either be O or 1
// You need to find the shortest distance between a given source cell to a destination cell. 
// The path can only be created out of a cell if its value is 1.
// If the path is not possible between source cell and destination cell, then return -1 

// We will solve this using Dijkstra Algorithm
// It can easily be solved using bfs

// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

#include<bits/stdc++.h>

using namespace std;

#define inf 1e8
#define pii pair<int, int>

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    pair<int, int> src, dest;
    cin>>src.first>>src.second>>dest.first>>dest.second;

    vector<vector<int>>dist(n, vector<int>(m, inf));
    dist[src.first][src.second] = 0;

    // Queue implementation of Djikstra
    // Here we do not need the priority queue as every node is on the same distance from its adjacent node so in queue it is already in sorted order
    queue<pii>q; 
    q.push(src);

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;

        q.pop();

        pii fnbr[4] = {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}};

        for(auto it : fnbr){
            if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m or grid[it.first][it.second] == 0) continue;

            if (dist[it.first][it.second] > dist[x][y] + 1){
                dist[it.first][it.second] = dist[x][y] + 1;

                q.push({it.first, it.second});
            }
        }
    }

    if (dist[dest.first][dest.second] == inf) cout<<-1;
    else cout<<dist[dest.first][dest.second];
}

// Sample Test Case
// 5 4
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0
// 1 0 0 0
// 0 1
// 2 2

// 5 4
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 0 0 0
// 1 1 1 1
// 0 1
// 4 3

// Output
// 3
// 8