// Problem

// You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. 
// Matrix elements is 0 if there is water or 1 if there is land.
// Originally, the 2D matrix is all 0 which means there is no land in the matrix.
// The array has k operator(s) and each operator has two integer A[i][0], A[i][1] 
// means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. 
// Return how many island are there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

// https://practice.geeksforgeeks.org/problems/number-of-islands/1

#include<bits/stdc++.h>

using namespace std;

class disjointSet{

    public:
        vector<vector<pair<int, int>>>parent;
        vector<vector<int>>size;

        disjointSet(int n, int m){
            parent.resize(n, vector<pair<int, int>>(m));
            size.resize(n, vector<int>(m, 0));

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    parent[i][j] = {i, j};
                }
            } 
        }

        pair<int, int> getUltParent(pair<int, int>p){
            int x = p.first, y = p.second;
            
            if (parent[x][y] == make_pair(x, y)) return {x, y};

            return parent[x][y] = getUltParent(parent[x][y]);
        }

        void unionBySize(pair<int, int> x, pair<int, int> y){
            x = getUltParent(x);
            y = getUltParent(y);

            if (x == y) return;

            if (size[x.first][x.second] > size[y.first][y.second]){
                parent[y.first][y.second] = x;
                size[x.first][x.second] += size[y.first][y.second];
            }
            else{
                parent[x.first][x.second] = y;
                size[y.first][y.second] += size[x.first][x.second];
            }
        }

};

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<int>>grid(n, vector<int>(m, 0));

    disjointSet ds(n, m);

    vector<int>ans;

    int islands = 0;
    for(int i = 0; i < k; i++){
        int x, y;
        cin>>x>>y;

        if (grid[x][y] == 1){
            ans.push_back(islands);
            continue;
        }

        grid[x][y] = 1;
        ds.size[x][y] = 1;

        pair<int, int>fnbr[4] = {{x+1, y}, {x, y+1}, {x-1, y}, {x, y-1}};

        int cnt = 0;
        for(auto it : fnbr){
            if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m) continue;
            else{
                if (grid[it.first][it.second] == 0) continue;

                if (ds.getUltParent({x, y}) != ds.getUltParent(it)){
                    ds.unionBySize(it, {x, y});
                    cnt++;
                } 
            }
        }

        if (cnt == 0) islands++;
        else islands -= (cnt-1);

        ans.push_back(islands);    
    }

    for(auto it : ans) cout<<it<<' ';
}

// Sample Test Cases

// 4 5 4
// 1 1
// 0 1
// 3 3
// 3 4

// 4 5 4
// 0 0
// 1 1
// 2 2
// 3 3

// 3 3 5
// 0 1
// 1 0
// 2 1
// 1 2
// 1 1

// Output

// 1 1 2 2
// 1 2 3 4
// 1 2 3 4 1