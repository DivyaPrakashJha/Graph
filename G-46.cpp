// Problem

// You are given a graph with n vertices and m edges.
// You can remove one edge from anywhere and add that edge between any two vertices in one operation.
// Find the minimum number of operations that will be required to make the graph connected.
// If it is not possible to make the graph connected, return -1.

// https://practice.geeksforgeeks.org/problems/connecting-the-graph/1

#include<bits/stdc++.h>

using namespace std;

class disjointSet{
    private:
        vector<int>parent, size;

    public:
        disjointSet(int n){
            parent.resize(n);
            size.resize(n, 1);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }        
        }

        int getUltParent(int x){
            if (parent[x] == x) return x;

            return parent[x] = getUltParent(parent[x]);
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

        int countConnectedComponents(){
            int cnt = 0;
            for(int i = 0; i < parent.size(); i++){
                if (parent[i] == i) cnt++;
            }
            
            return cnt;
        }
};

int main(){
    int n, m;
    cin>>n>>m;

    disjointSet ds(n);

    int cnt = 0;
    for(int i = 0, u, v; i < m; i++){
        cin>>u>>v;

        if (ds.getUltParent(u) == ds.getUltParent(v)){
            cnt++;
        }
        else ds.unionBySize(u, v);
    }

    int x = ds.countConnectedComponents();
    // we need atleast x-1 edges to connect these

    if (cnt >= x-1) cout<<x-1;
    else cout<<-1; 
}

// Sample Test Case

// 6 5
// 0 1
// 0 2
// 0 3
// 1 2
// 1 3

// Output

// 2
