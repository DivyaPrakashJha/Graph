// Kahn's Algorithm - Topological Sorting using bfs

#include<bits/stdc++.h>

using namespace std;

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v);

    // Indegree - No of incoming edges to a node
    vector<int>indegree(v, 0); 
    
    for(int i = 0, u, w; i < e; i++){
        cin>>u>>w;

        g[u].push_back(w);
        indegree[w]++;
    }

    vector<int>vis(v, 0);

    queue<int>q;

    // Push all the nodes with 0 indegree into the queue
    // Now remove them one by one from the graph along with their edges and accordingly modify the indegree of nodes connected to it
    // If the indegree of some node becomes 0, push them into the queue and repeat the process till queue isn't empty

    vector<int>topologicalSort;
    
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

    for(auto it : topologicalSort){
        cout<<it<<" ";
    }

}

// T.C. - O(v+e)
// S.C. - O(v)

// Sample Test Case
// 6 7
// 0 3
// 0 4
// 2 0
// 2 3
// 5 3
// 5 4
// 4 1

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

// One of the possible output
// 2 5 0 3 4 1
// 6 7 3 1 5 0 2 4