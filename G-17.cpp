#include<bits/stdc++.h>

using namespace std;

// Detect a Cycle in a Directed Graph

bool dfs(int v, vector<vector<int>>&g, vector<int>&vis, vector<int>&pathVis){
    vis[v] = 1;
    pathVis[v] = 1;

    for (auto it : g[v]){
        if (!vis[it]){
            if (dfs(it, g, vis, pathVis) == true) return true;
        }
        else if (vis[it] and pathVis[it]) return true;
    }

    pathVis[v] = 0;
    return false;
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v+1);

    for(int i = 0, u, w; i < e; i++){
        cin>>u>>w;

        g[u].push_back(w);
    }

    vector<int>vis(v+1, 0);

    // For a cycle to be present in a directed graph, the nodes should be in the same path
    // So we use a path visited array/vector to keep track of the path
    // We mark the pathVis[i] as 1, when we go to node i,
    // We unmark the pathVis[i] at the end so as to avoid wrong detection of cycle when the recursion backtracks

    // Consider this graph for clarity :
    // 10 11
    // 1 2
    // 2 3
    // 3 7
    // 3 4
    // 4 5
    // 7 5
    // 5 6
    // 8 2
    // 8 9
    // 9 10
    // 10 8

    // Observe the 3-4-5-7 part
    // dfs(3)->dfs(4)->dfs(5)->dfs(6) (3, 4, 5, 6 marked visited)
    // Now after dfs(6) it backtracks to dfs(5)->dfs(4)->dfs(3)
    // Then it goes to dfs(3)->dfs(7) and now when it sees its adjacent node 5, 
    // it finds it visited so it will detect a cycle but that's not the case
    // So we need a pathVis array to keep track of the path

    vector<int>pathVis(v+1, 0); // We can also use a single visited array marking visited as 1 and pathVisited as 2 

    for(int i = 1; i <= v; i++){ // In case of multiple connected components
        if (!vis[i]){
            if (dfs(i, g, vis, pathVis) == true){
                cout<<"Yes";
                return 0;
            }
        }
    }

    cout<<"No";
}

// T.C. - O(v+e)
// S.C. - O(v)

// Sample Test Case
// 10 10
// 1 2
// 2 3
// 3 7
// 3 4
// 4 5
// 7 5
// 5 6
// 8 2
// 8 9
// 9 10

// 10 11
// 1 2
// 2 3
// 3 7
// 3 4
// 4 5
// 7 5
// 5 6
// 8 2
// 8 9
// 9 10
// 10 8

// Output
// No
// Yes