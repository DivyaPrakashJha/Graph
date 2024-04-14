#include<bits/stdc++.h>

using namespace std;

// Detect a cycle in an undirected graph using dfs

bool dfs(int v, int parent, vector<vector<int>>&g, vector<int>&visited){
    visited[v] = 1;

    for(auto it : g[v]){
        if (!visited[it]){
            if (dfs(it, v, g, visited) == true) return true;
        }
        else{
            if (it != parent){ // If the node is visited and it is not the parent, then there must be a cycle
                return true;
            }
        }
    }

    return false;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v+1);
    for(int i = 0, u, v; i < e; i++){
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int>visited(v+1, 0);

    for(int i = 0; i < v; i++){
        if (!visited[i]){
            if (dfs(i, -1, g, visited) == true){
                cout<<"Yes";
                return 0;
            }
        }
    }

    cout<<"No";

}

// TC - O(v+e)
// SC - O(v)

// Sample Test Case

// 7 7
// 1 2
// 1 3
// 3 4
// 3 6
// 6 7
// 5 7
// 2 5

// 9 7
// 1 2
// 1 3
// 2 4
// 5 6
// 7 8
// 8 9
// 7 9

// 9 6
// 1 2
// 1 3
// 2 4
// 5 6
// 8 9
// 7 9

// Output
// Yes 
// Yes
// No