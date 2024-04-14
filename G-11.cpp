// Problem

// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as [i1 - i2] + [j1 - j2],
// where i1,j1 are the row number and column number of the current cell, 
// and i2, j2 are the row number and column number of the nearest cell having value 1.

// Multisource bfs

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

    vector<vector<int>>ans(n, vector<int>(m, 0));
    queue<pair< pair<int, int>, int >>q; // Node(i, j), level

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                q.push({ {i, j}, 0 });
            }
        }
    }

    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int lev = q.front().second;

        q.pop();

        // Clearly only vertical and horizontal movements are allowed

        pair<int, int>fnbr[4] = { {i-1, j}, {i, j-1}, {i, j+1}, {i+1, j} }; // Four neighbours

        for (auto it : fnbr){
            if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m) continue;
            else if (grid[it.first][it.second] == 0 and ans[it.first][it.second] == 0){
                q.push( { {it.first, it.second}, lev+1 } );
                ans[it.first][it.second] = lev+1;
            }
        }
    }


    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

// TC - O(nm)
// SC - O(nm)

// Sample Test Case
// 3 3
// 0 0 0
// 0 1 0
// 1 0 1


// Output
// 2 1 2 
// 1 0 1 
// 0 1 0 