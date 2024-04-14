#include<bits/stdc++.h>

using namespace std;

// Detect a cycle in an undirected graph using bfs

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v+1);
    for(int i = 0, u, v; i < e; i++){
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int>vis(v+1, 0);

    for(int i = 1; i <= v; i++){ // Running this loop in case the graph has multiple connected components
        queue<pair<int, int>>q; // Node, Parent

        if (!vis[i]){
            q.push({i, -1});
            vis[i] = 1;

            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;

                q.pop();

                for(auto it : g[node]){
                    if (!vis[it]){
                        q.push({it, node});
                        vis[it] = 1;
                    }
                    else if (vis[it] and it != parent){
                        cout<<"Yes";
                        return 1;
                    }
                }
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