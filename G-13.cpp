// Problem

// You are given an n x m binary matrix grid, where O represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }

    // All the 1's connected to boundary 1's (Connected Components) can be used to walk off the boundary
    // Remaining are 1's for which we cannot walk off the boundary

    vector<vector<int>>visited(n, vector<int>(m, 0));

    queue<pair<int, int>>q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (mat[i][j] == 1 and (i == 0 or j == 0 or i == n-1 or j == m-1) ){
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        pair<int, int>fnbr[4] = { {i-1, j}, {i, j-1}, {i, j+1}, {i+1, j} }; // Four neighbours

        for (auto it : fnbr){
            if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m) continue;
            else if (mat[it.first][it.second] == 1 and !visited[it.first][it.second]){
                q.push({it.first, it.second});
                visited[it.first][it.second] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (mat[i][j] == 1 and !visited[i][j]) cnt++;
        }
    }

    cout<<cnt;
}

// TC - O(nm)
// SC - O(nm)

// Sample Test Case
// 5 5
// 0 0 0 1 1
// 0 0 1 1 0
// 0 1 0 0 0
// 0 1 1 0 0
// 0 0 0 1 1

// 6 5
// 0 0 0 1 1
// 1 1 0 0 1
// 0 1 0 1 0
// 0 0 1 0 1
// 0 1 1 1 0
// 0 0 0 0 1

// Output
// 3
// 5