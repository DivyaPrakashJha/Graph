// Problem

// Given a grid Of size n* m (n is the number Of rows and m is the number Of columns in the grid)
// consisting Of 'O's (Water) and '1 's(Land).
// Find the number Of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands 
// horizontally or vertically or diagonally i.e., in all 8 directions.

// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, vector<vector<int>>&grid, int n, int m, vector<vector<int>>&visited){
    visited[i][j] = 1;

    for(int k = i-1; k <= i+1; k++){
        for(int l = j-1; l <= j+1; l++){
            if (k < 0 or l < 0 or k >= n or l >= m) continue;
            else if (grid[k][l] == 1 and !visited[k][l]){
                dfs(k, l, grid, n, m, visited);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>visited(n, vector<int>(m, 0));

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] == 1 and !visited[i][j]){
                cnt++;
                // dfs(i, j, grid, n, m, visited);

                // OR

                queue<pair<int, int>>q; // bfs
                q.push({i, j});
                visited[i][j] = 1;

                while(!q.empty()){
                    pair<int, int>p = q.front();
                    q.pop();

                    for (int k = p.first-1; k <= p.first+1; k++){
                        for (int l = p.second-1; l <= p.second+1; l++){
                            if (k < 0 or l < 0 or k >= n or l >= m) continue;
                            else if (!visited[k][l] and grid[k][l] == 1){
                                q.push({k, l});
                                visited[k][l] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<cnt;
}

// Sample Test Case
// 4 2
// 0 1
// 1 1
// 0 1
// 1 0

// 4 5
// 1 0 1 0 1
// 0 1 0 0 1
// 0 0 0 1 1
// 1 1 0 0 0

// Output
// 1
// 3