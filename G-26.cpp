// Shortest Path in a directed acyclic graph using topological sort

// For a general weighted graph, we can calculate single source shortest distances in O(VE) time using Bellman–Ford Algorithm. 
// For a graph with no negative weights, we can do better and calculate single source shortest distances in O(E + VLogV) time using Djikstra’s algorithm.
// We can calculate single source shortest distances in O(V+E) time for DAGs using Topological Sorting.

#include<bits/stdc++.h>

using namespace std;

#define inf 1e8

void dfs(int v, vector<vector< pair<int, int> >>&g, vector<int>&vis, stack<int>&st){
    vis[v] = 1;

    for(auto it : g[v]){
        if (!vis[it.first]){
            dfs(it.first, g, vis, st);
        }
    }

    st.push(v);
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector< pair<int, int> >>g(n);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;

        g[u].push_back({v, w});
    }

    vector<int>vis(n, 0);
    stack<int>st;

    // We first find the topological sort for the above data
    for(int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, g, vis, st);
        }
    }

    vector<int>dist(n, inf);

    int source;
    cin>>source;

    dist[source] = 0;

    while(!st.empty()){
        int t = st.top();
        st.pop();
        // cout<<t<<" ";

        // Now we accordingly update the distance
        for(auto it : g[t]){
            dist[it.first] = min(dist[it.first], dist[t]+it.second);
        }
    }

    for(int i = 0; i < n; i++){
        if (dist[i] == inf) dist[i] = -1;
        cout<<i<<" "<<dist[i]<<endl;
    }
        
}

// Sample Test Case

// 6 8
// 0 2 1
// 0 1 2
// 5 1 1
// 5 3 2
// 3 1 1
// 3 4 2
// 2 3 4
// 2 4 3
// 0

// Output

// 0 0
// 1 2
// 2 1
// 3 5
// 4 4
// 5 -1