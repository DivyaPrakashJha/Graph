// Shortest path in a undirected graph having unit distance

#include<bits/stdc++.h>

using namespace std;

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v);
    for(int i = 0, u, w; i < e; i++){
        cin>>u>>w;

        g[u].push_back(w);
        g[w].push_back(u);
    }

    // We will perform a simple bfs to find the shortest distance

    vector<int>dist(v, -1);
    
    int src;
    cin>>src;
    dist[src] = 0;

    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(auto it : g[x]){
            if (dist[it] == -1){ // Not visited
                dist[it] = dist[x] + 1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i < v; i++){
        cout<<i<<' '<<dist[i]<<endl;
    }
}

// Sample Test Case

// 6 7
// 0 2
// 0 1
// 1 5
// 1 3
// 2 3
// 3 4
// 3 5
// 0

// Output
// 0 0
// 1 1
// 2 1
// 3 2
// 4 3
// 5 2