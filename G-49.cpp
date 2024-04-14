// Problem

// You are given an n xn binary grid. A grid is said to be binary if every value in grid is either 1 or 0.
// You can change at most one cell in grid from O to 1.
// You need to find the largest group of connected 1's.
// Two cells are said to be connected if both are adjacent to each other and both have same value.

// https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

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
    int n, m;
    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    disjointSet ds(n, m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] == 1){

                ds.size[i][j] = max(ds.size[i][j], 1);

                int x1 = i, y1 = j+1;
                int x2 = i+1, y2 = j;

                if (y1 < m){
                    if (grid[x1][y1] == 1){
                        ds.size[x1][y1] = max(ds.size[x1][y1], 1);
                        ds.unionBySize({i, j}, {x1, y1});
                    }
                }
                if (x2 < n){
                    if (grid[x2][y2] == 1){
                        ds.size[x2][y2] = max(ds.size[x2][y2], 1);
                        ds.unionBySize({i, j}, {x2, y2});
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] == 0){
                pair<int, int>fnbr[4] = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};

                int sz = 0;
                set<pair<int, int>>st;
                for(auto it : fnbr){
                    if (it.first < 0 or it.second < 0 or it.first >= n or it.second >= m) continue;

                    if (grid[it.first][it.second] == 1){
                        pair<int, int>p = ds.getUltParent(it);
                        st.insert(p);
                    }    
                }

                for(auto it : st){
                    sz += ds.size[it.first][it.second];
                }

                ans = max(ans, sz+1);
           }
        }
    }

    if (ans == 0){ // No zeroes are present => all ones
        ans = m*n;
    }

    cout<<ans;

}

// Sample Test Case

// 5 6
// 1 1 1 0 1 1
// 1 1 0 1 1 1
// 1 1 0 1 1 0
// 0 0 1 0 0 1
// 1 1 1 1 1 1

// 4 3
// 1 1 1
// 1 1 1 
// 1 1 1
// 1 1 1

// Output

// 23
// 12