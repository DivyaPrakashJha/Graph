// Problem

// Given a matrix mat of size N x M where every element is either 'O' or 'X'.
// Replace all 'O' with 'X' that are surrounded by 'X'.
// A 'O' (or a set of 'O') is considered to be by surrounded by 'X'
// if there are 'X' at locations just below, just above, just left and just right of it.

// Example:

// Input
// n = 5, m = 4;
// X X X X
// X O X X
// X O O X
// X O X X
// X X O O

// Output:
// X X X X
// X X X X
// X X X X
// X X X X
// X X O O

#include<bits/stdc++.h>

using namespace std;

void dfs(int i, int j, vector<vector<char>>&mat, vector<vector<char>>&ans, int n, int m){
    ans[i][j] = 'C'; // Indicating these O's cannot be converted

    pair<int, int>fnbr[4] = { {i-1, j}, {i, j-1}, {i, j+1}, {i+1, j} }; // Four neighbours

    for (auto it : fnbr){
        if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m) continue;
        else if (mat[it.first][it.second] == 'O' and ans[it.first][it.second] == 'O'){
            dfs(it.first, it.second, mat, ans, n, m);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>>mat(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }

    // Observation

    // if any 'O' is on the boundary, it along with its connected zeroes(connected components) cannot be converted to 'X' 
    // as they will not have 'X'(s) all around them.
    
    // Rest 'O's are bound to be surrounded by 'X', so convert them to 'X'

    vector<vector<char>>ans = mat;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 or j == 0 or i == n-1 or j == m-1){
                if (mat[i][j] == 'O'){
                    dfs(i, j, mat, ans, n, m);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (ans[i][j] == 'C') ans[i][j] = 'O';
            else if (ans[i][j] == 'O') ans[i][j] = 'X';
            
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

// TC - O(nm)
// SC - O()

// Sample Test Case
// 5 5
// X X X X X
// X O O X O
// X X O X O
// X O X O X
// O O X X X

// Output
// X X X X X
// X X X X O
// X X X X O
// X O X X X
// O O X X X




