// Problem

// Given a grid of dimension nxm where each cell in the grid can have values O, 1 or 2 which has the following meaning:
// O : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges
// We have to determine what is the minimum time required to rot all oranges.
// A rotten orange at index [i,jl can rot Other fresh orange at indexes 
// [i-l,j], [i+l ,j], [i,j-l], [i,j+l] (up, down, left and right) in unit time.

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    // Multisource bfs
    queue<pair<int, int>>q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] == 2){
                q.push({i, j});
            }
        }
    }

    q.push({-1, -1}); // For tracking levels, can also use a queue<pair< pair<int, int>, int >> to denote the level
    int time = 0;

    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();

        if (i == -1 and j == -1){
            time++;

            if (!q.empty()) q.push({-1, -1});
            continue;
        }

        pair<int, int>fnbr[4] = { {i-1, j}, {i, j-1}, {i, j+1}, {i+1, j} };

        for (auto it : fnbr){
            if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m) continue;
            else if (grid[it.first][it.second] == 1){
                q.push({it.first, it.second});
                grid[it.first][it.second] = 2;
            }
        } 
    }

    // Checking if any orange is not rotten (non reachable)
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                cout<<-1;
                return 0;
            }
        }
    }

    cout<<time-1;
}

// SC - O(nm)
// TC - O(nm)

// Sample Test Case
// 3 3
// 0 1 2
// 0 1 2
// 2 1 1

// 3 3
// 1 2 1
// 1 1 0
// 0 0 1

// 3 3
// 0 1 2
// 0 1 1
// 2 1 1

// Output
// 1
// -1
// 2