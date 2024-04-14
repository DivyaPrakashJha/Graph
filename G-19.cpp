// Topological Sorting

// Linear oredering of vertices such that if there is an edge between u and v, then u appears before v in that ordering
// There can be multiple valid orderings

// Exists only on directed acyclic graphs

// Example
// 6 6
// 5 0
// 4 0
// 5 2
// 2 3
// 3 1
// 4 1

// 5 4 2 3 1 0
// 4 5 2 3 1 0

#include<bits/stdc++.h>

using namespace std;

// Use the dfs method to find topological sort only if it is known for sure that the graph is directed acyclic

void dfs(int v, vector<vector<int>>&g, vector<int>&vis, stack<int>&st){
    vis[v] = 1;

    for (auto it : g[v]){
        if (!vis[it]){
            dfs(it, g, vis, st);
        }
    }

    st.push(v);
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
    stack<int>st;

    for(int i = 0; i < v; i++){
        if (!vis[i]){
            dfs(i, g, vis, st);
        }
    }

    vector<int>topologicalSorting;
    while(!st.empty()){
        topologicalSorting.push_back(st.top());
        st.pop();
    }

    for(auto it : topologicalSorting) cout<<it<<" ";
}

// T.C. - O(v+e)
// S.C. - O(v)  