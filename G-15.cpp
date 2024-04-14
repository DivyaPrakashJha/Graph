// Bipartite Graph

// A graph is said to be bipartite if we can color the graph with 2 different colors such that no adjacent nodes have the same color.

// Observations:
// Linear graphs (acyclic graphs) are bipartite
// Cyclic graphs with every cycle of even length are also bipartite
// Cyclic graphs containing a cycle of odd length are never bipartite

// Check for bipartite graphs using bfs

#include<bits/stdc++.h>

using namespace std;

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>>g(v+1);

    for(int i = 0, u, w; i < e; i++){
        cin>>u>>w;

        g[u].push_back(w);
        g[w].push_back(u);
    }

    // Idea
    // We take two colors (0 and 1)
    // If we color a particular node with a color x then we color all its adjacent nodes with color y
    // If at any point two adjacent nodes have the same color, we say that the graph is not a bipartite graph
    // Else it is a bipartite graph

    vector<int>color(v+1, -1);

    queue<int>q;
    q.push(1);
    color[1] = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto it : g[x]){
            if (color[it] == -1){
                color[it] = 1-color[x];
                q.push(it);
            }
            else if(color[it] == color[x]){
                cout<<"Not Bipartite";
                return 0;
            }
        }
    }

    cout<<"Bipartite";
}

// T.C. - O(v+e)
// S.C. - O(v)

// Sample Test Case
// 8 8
// 1 2
// 2 6
// 2 3
// 3 4
// 4 5
// 4 7
// 7 8

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