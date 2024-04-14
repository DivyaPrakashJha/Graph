// Dijkstra's Algorithm

// It is used to find the shortest distance from a source node to all the other nodes

// Implementation using Min heap(Minimum Priority Queue)
// We can also implement this using queue but it is more time consuming Unnecessary exploration of paths) - More of a brute force approach
// Using priority queue we always take the minimal distance first (greedy)

#include<bits/stdc++.h> 

using namespace std;

#define inf 1e8
#define pii pair<int, int>

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pii>>g(n); // Vertex1 - {Vertex2, Weight}

    for(int i = 0, u, v, w; i < m; i++){
        cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int src = 0;
    cin>>src;

    vector<int>dist(n, inf);
    priority_queue< pii, vector<pii>, greater<pii> >pq; // {Dist, Node} // Min Heap : Smallest dist at the top 

    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()){
        int node = pq.top().second;

        pq.pop();

        for(auto it : g[node]){
            if(dist[it.first] > dist[node] + it.second){ // dist[newNode] = min(dist[newNode], dist[currNode]+weight)
                pq.push({dist[node] + it.second, it.first});

                dist[it.first] = dist[node] + it.second;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<i<<' '<<dist[i]<<endl;
    }

    // Dijkstra algorithm cannot be used in graphs having negative weight(s) or negative weight cycle
    // Example: Consider a graph having two nodes 0 and 1 having weight -2, src = 0
    // 1st Iteration : dist[0] = 0, dist[1] = -2
    // 2nd Iteration : dist[0] = -4, dist[1] = -2
    // 3rd Iteration : dist[0] = -4, dist[1] = -6
    // Hence, it will run forever

}

// T.C. - O(ElogV)

// Sample Test Case
// 6 8
// 0 1 4
// 0 2 4
// 1 2 2
// 2 3 3
// 2 4 1
// 2 5 6
// 3 5 2
// 4 5 3
// 0

// Output
// 0 0
// 1 4
// 2 4
// 3 7
// 4 5
// 5 8