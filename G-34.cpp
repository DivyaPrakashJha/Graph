//  Problem

// You are a hiker preparing for an upcoming hike. 
// You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col).
// You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
// You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9
#define pii pair<int, int>

int main(){
    int r, c;
    cin>>r>>c;

    vector<vector<int>>grid(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>grid[i][j];
        }
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>pq;
    vector<vector<int>>effort(r, vector<int>(c, inf));

    effort[0][0] = 0;

    pq.push({0, {0, 0}});

    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int d = pq.top().first;
        
        if (x == r-1 and y == c-1){
            cout<<d;
            return 0;
        }
        
        pq.pop();

        pii fnbr[4] = {{x+1, y}, {x-1, y}, {x, y-1}, {x, y+1}};

        for(auto it : fnbr){
            if (it.first < 0 or it.second < 0 or it.first >= r or it.second >= c) continue;

            int diff = abs(grid[x][y] - grid[it.first][it.second]);
            int t = max(d, diff);

            if (t < effort[it.first][it.second]){
                effort[it.first][it.second] = t;
                pq.push({t, {it.first, it.second}});
            }
        }
    }  

}

// Sample Test Case

// 3 3
// 1 2 2
// 3 8 2
// 5 3 5

// Output
// 2 (1-3-5-3-5)