// Prim's Algorithm

// 1. Initialize an MST with the randomly chosen vertex.
// 2. Find all the edges that connect the tree in the above step with the new vertices.
// 3. From the edges found, select the minimum edge and add it to the tree.
//    Repeat step 2 and 3 until the minimum spanning tree is formed.

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>>g(n);

    for(int i = 0, u, v, w; i < m; i++){
        cin>>u>>v>>w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }


    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq; // {Weight, {node, parent}}
    vector<int>visited(n, 0);

    vector<pair<int, pair<int, int>>>mstEdges;

    pq.push({0, {0, -1}});

    while(!pq.empty()){
        int w = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;

        pq.pop();
        
        // Mark the node as visited only when we are going to add it to the MST
        if (!visited[node]){
            visited[node] = 1;

            if (par != -1) mstEdges.push_back({w, {node, par}});
        }
        else continue;

        for(auto it : g[node]){
            if (!visited[it.first]){
                pq.push({it.second, {it.first, node}});
            }
        }
    }

    int sum = 0;
    for(auto it : mstEdges){
        sum += it.first;

        cout<<it.second.first<<" - "<<it.second.second<<"  "<<it.first<<endl;
    }

    cout<<"Minimum Sum : "<<sum;
}

// T.C. - O(ElogV)
// S.C. - O(E)

// Sample Test Case

// 5 6
// 0 2 1
// 0 1 2
// 2 1 1
// 2 3 2
// 2 4 2
// 3 4 1

// Output

// 2 - 0  1
// 1 - 2  1
// 3 - 2  2
// 4 - 3  1
// Minimum Sum : 5