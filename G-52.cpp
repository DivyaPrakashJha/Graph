// Bridges in Graph (Tarjan's Algorithm)

// Any edge on whose removal the graph is broken down into multiple components is called a bridge

// To implement this algorithm, we will need –

// time[]
// Dfs insertion time
// to keep track when for the first time that particular vertex is reached

// low[]
// to keep track of the lowest possible time by which we can reach that vertex ‘other than parent’ 
// so that if edge from parent is removed can the particular node can be reached other than parent.

// We will traverse the graph using DFS traversal but with slight modifications 
// i.e. while traversing we will keep track of the parent node by which the particular node is reached 
// because we will update the low[node] = min(low[all it’s adjacent node except parent]) hence we need to keep track of the parent.

// While traversing adjacent nodes let ‘v’ of a particular node let ‘u’, 3 cases arise –

// 1. v is parent of u then, 
// skip that iteration.

// 2. v is visited then,
// update the low of v i.e. low[u] = min( low[u] , disc[v]) this arises when a node can be visited by more than one node, 
// but low is to keep track of the lowest possible time so we will update it.

// 3. v is not visited then,

// call the DFS to traverse ahead
// now update the low[u] = min( low[u], low[v] ) as we know v can’t be parent cause we have handled that case first.
// now check if ( low[v] > time[u] ) i.e. the lowest possible to time to reach ‘v’ is greater than ‘u’ 
// this means we can’t reach ‘v’ without ‘u’ so the edge   u -> v is a bridge.

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9

vector<pair<int, int>>ans;
int timer = 0;

void dfs(int v, vector<vector<int>>&g, vector<int>&visited, vector<int>&time, vector<int>&low, int parent){
    visited[v] = 1;
    time[v] = low[v] = timer;
    timer++;

    for(auto it : g[v]){
        if (!visited[it]){
            dfs(it, g, visited, time, low, v);
        }

        if (it != parent){
            low[v] = min(low[v], low[it]);
        }
    }

    if (low[v] > time[parent]) ans.push_back({v, parent});
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>graph(n+1);
    for(int i = 0, u, v; i < m; i++){
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int>visited(n+1, 0);
    vector<int>time(n+1, 0);
    vector<int>low(n+1, inf);

    for(int i = 0; i < n; i++){
        if (!visited[i]){
            time[i] = 0;
            dfs(i, graph, visited, time, low, 0);
        }
    }

    for(auto it: ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

}

// T.C. - O(V+E)
// S.C. - O(V+E)

// Sample Test Case

// 7 8
// 0 1
// 1 2
// 2 0
// 0 3
// 3 4
// 4 5
// 4 6
// 5 6

// 6 6
// 0 1
// 1 2
// 2 3
// 3 4
// 4 5
// 5 1

// Output

// 4 3
// 3 0

// 1 0