//  Dijkstra's Algorithm

// Implementation using Set
// Set stores unique elements in ascending order (Smallest at the top)
// It is sometimes faster than the priority queue approach depending on the graph
// As we can erase elements from sets so it reduces the number of iterations

// As soon as we find a better distance to a particular node which is earlier visited i.e. dist[i] != inf,
// We insert the {better distance, node} in the set while erasing the {old distance, node} from the set

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
    set<pair<int, int>>s; // {dist, node}

    dist[src] = 0;
    s.insert({0, src});

    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        s.erase(it);

        for(auto it : g[node]){
            if (dist[it.first] > dist[node]+it.second){
                if (dist[it.first] != inf){
                    s.erase({dist[it.first], it.second});
                }
                s.insert({dist[node]+it.second, it.first});
                dist[it.first] = dist[node] + it.second;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<i<<" "<<dist[i]<<endl;
    }

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