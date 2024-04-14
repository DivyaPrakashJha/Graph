// Check for bipartite Graphs using dfs

#include<bits/stdc++.h>

using namespace std;

bool dfs(int v, vector<vector<int>>&g, vector<int>&color, int col){
    color[v] = col;

    for (auto it : g[v]){
        if (color[it] == -1){
            if (dfs(it, g, color, 1-col) == false) return false;
        }
        else if (color[it] == col){
            return false;
        }
    }

    return true;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v+1);

    for(int i = 0, u, w; i < e; i++){
        cin>>u>>w;

        g[u].push_back(w);
        g[w].push_back(u);
    }

    vector<int>color(v+1, -1);

    if (dfs(1, g, color, 0) == false){
        cout<<"Not Bipartite";
    }
    else cout<<"Bipartite";
}

// T.C - O(v+e)
// S.C - O(v)

// Sample Test Case
// 8 8
// 1 2
// 2 6
// 2 3
// 3 4
// 4 5
// 4 7
// 7 8
// 5 6

// 6 6
// 1 2
// 2 3
// 2 5
// 3 4
// 5 4
// 4 6

// 6 7
// 1 2
// 2 3
// 2 5
// 3 4
// 5 4
// 4 6
// 3 5


// Output
// Not Bipartite
// Bipartite
// Not Bipartite