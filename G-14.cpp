// Problem

// Given a boolean 2D matrix grid of size n * m. 
// You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. 
// Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

// Approach

// We just traverse through all the islands(connected components) and store their shape in a set
// The number of different shapes in the set at the end will be the answer

#include<bits/stdc++.h>

using namespace std;

void dfs(int i, int j, vector<vector<int>>&grid, int n, int m, vector<vector<int>>&visited, vector<char>&shape, char dir){
    visited[i][j] = 1;
    shape.push_back(dir);

    pair< pair<int, int>, char >fnbr[4] = { {{i-1, j}, 't'}, {{i, j-1}, 'l'}, {{i, j+1}, 'r'}, {{i+1, j}, 'b'} }; // Four neighbours

    for (auto it : fnbr){
        if (it.first.first < 0 or it.first.second < 0 or it.first.first >= n or it.first.second >= m) continue;
        else if (grid[it.first.first][it.first.second] == 1 and !visited[it.first.first][it.first.second]){
            dfs(it.first.first, it.first.second, grid, n, m, visited, shape, it.second);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>vis(n, vector<int>(m, 0));
    set< vector<char> >islandShapes;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1 and !vis[i][j]){
                vector<char>shape;  
                dfs(i, j, grid, n, m, vis, shape, 'm');
                islandShapes.insert(shape);
            }
        }
    }
    for(auto it : islandShapes){
        for(auto it1 : it){
            cout<<it1;
        }
        cout<<endl;
    }
    cout<<islandShapes.size(); 
}

// T.C - O(nmlog(nm))
// S.C - O(nm)

// Sample Test Case
// 5 5
// 1 1 0 1 1
// 1 0 0 0 0
// 0 0 0 1 1
// 1 1 0 1 0
// 0 0 0 0 0

// 5 4
// 1 1 1 0
// 0 1 0 1
// 0 0 0 0
// 1 1 1 0
// 0 1 0 1

// Output
// 2
// 2