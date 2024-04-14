// Problem

// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
// and a pixel value newColor, "flood fill" the image.
// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same
// color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on.
// Replace the color of all of the aforementioned pixels with the newCoIor.

#include<bits/stdc++.h>

using namespace std;

void dfs(int i, int j, vector<vector<int>>&img, int n, int m, int nc, int oc){
    img[i][j] = nc;

    pair<int, int>fnbr[4] = { {i-1, j}, {i, j-1}, {i, j+1}, {i+1, j} };

    for (auto it : fnbr){
        if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m) continue;
        else if (img[it.first][it.second] == oc) dfs(it.first, it.second, img, n, m, nc, oc);
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>img(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>img[i][j];
        }
    }

    int sr, sc, newColor;
    cin>>sr>>sc>>newColor;

    int oldColor = img[sr][sc];

    dfs(sr, sc, img, n, m, newColor, oldColor);

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }

}

// TC - O(nm)
// SC - O(nm)

// Sample Test Case
// 3 3
// 1 1 1
// 1 1 0
// 1 0 1
// 0 0 2

// Output
// 2 2 2 
// 2 2 0 
// 2 0 1