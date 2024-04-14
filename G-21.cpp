// Detect a cycle in a directed graph using Topological Sorting

// Suppose the graph has n vertices
// If we are not able to generate a Topological Sort of n size then the graph is having a cycle
// Else it does not have a cycle

#include<bits/stdc++.h>

using namespace std;

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v);
    vector<int>indegree(v, 0); 
    
    for(int i = 0, u, w; i < e; i++){
        cin>>u>>w;

        g[u].push_back(w);
        indegree[w]++;
    }

    vector<int>vis(v, 0);

    queue<int>q;

    vector<int>topologicalSort; // We can also use a cnt variable as we only need the size not the ordering 
    
    for(int i = 0; i < v; i++){
        if (indegree[i] == 0){
            q.push(i);
            vis[i] = 1;
            topologicalSort.push_back(i);
        }
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto it : g[t]){
            if (!vis[it]){
                indegree[it]--;
                if (indegree[it] == 0){
                    q.push(it);
                    vis[it] = 1;
                    topologicalSort.push_back(it);
                }
            }
        }        
    }

    if (topologicalSort.size() == v) cout<<"No Cycle Present";
    else cout<<"Cycle Present";
}


// Sample Test Case

// 8 11
// 0 2
// 1 0
// 1 2
// 3 1
// 3 4
// 2 4
// 5 4
// 3 5
// 7 5
// 6 7
// 6 3

// 8 11
// 0 2
// 1 0
// 2 1
// 3 1
// 3 4
// 2 4
// 5 4
// 3 5
// 7 5
// 6 7
// 6 3

// Output
// Cycle Not Present
// Cycle Present