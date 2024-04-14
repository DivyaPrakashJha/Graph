// Kruskal's Algorithm

// 1. Sort all the edges from low weight to high.
// 2. Take the edge with the lowest weight and add it to the spanning tree. 
//    If the edge to be added creates a cycle, then reject the edge.
// 3. Continue to add the edges until we reach all vertices, and a minimum spanning tree is created.

#include<bits/stdc++.h>

using namespace std;

class disjointSet{
    private:
        vector<int>parent;
        vector<int>size;

    public:
        disjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);

            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }        
        }

        int getUltParent(int x){
            if (parent[x] == x) return x;

            return parent[x] = getUltParent(parent[x]);
        }

        bool isSameComponent(int x, int y){
            if (getUltParent(x) == getUltParent(y)) return 1;

            return 0;
        }

        void unionBySize(int x, int y){
            x = getUltParent(x);
            y = getUltParent(y);

            if (x == y) return; 
            
            if (size[x] < size[y]){
                parent[x] = y;
                size[y] += size[x];
            }
            else{
                parent[y] = x;
                size[x] += size[y];
            }
        }
};

int main(){
    int n, m; 
    cin>>n>>m;

    vector<pair<int, pair<int, int>>>edges; // {Weight, {u, v}}

    for(int i = 0, u, v, w; i < m; i++){
        cin>>u>>v>>w;

        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    disjointSet ds(n+1);

    vector<pair<int, pair<int, int>>>mstEdges; 

    for(auto it : edges){
        int x = it.second.first;
        int y = it.second.second;

        if (ds.isSameComponent(x, y)) continue;
        else{
            mstEdges.push_back(it);
            ds.unionBySize(x, y);
        }
    }

    int sum = 0;
    for(auto it : mstEdges){
        sum += it.first;
        cout<<it.second.first<<" - "<<it.second.second<<"  "<<it.first<<endl;
    }

    cout<<"Minimum Sum : "<<sum;  

}

// T.C. - O(ElogE)
// S.C. - O(V+E)

// Sample Test Case 

// 5 6
// 0 2 1
// 0 1 2
// 2 1 1
// 2 3 2
// 2 4 2
// 3 4 1

// Output
 
// 0 - 2  1
// 2 - 1  1
// 3 - 4  1
// 2 - 3  2
// Minimum Sum : 5