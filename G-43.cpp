// Disjoint Set 

// Two operations : 
// 1. Find Parent
// 2. Union
//    2.1 Union by rank
//    2.2 Union by size

#include<bits/stdc++.h>

using namespace std;

class DisjointSet{
    vector<int>rank, parent, size;

    public:

    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]) return node;

        // return findUltimateParent(parent[node]); // Without Path Compression
        
        return parent[node] = findUltimateParent(parent[node]); // With Path Compression 
        // It will go to the base case and while returning it will assign the ultimate parent to all the intermediate nodes
    }

    bool isSameComponent(int u, int v){
        if (findUltimateParent(u) == findUltimateParent(v)) return 1;
        
        return 0;
    }
    
    
    // -> Union by rank
        // 1. Find ultimate parent of u and v : pu and pv
        // 2. find rank of pu, pv
        // 3. Connect smaller rank to larger rank always
    void unionByRank(int u, int v){
        int ultPar_u = findUltimateParent(u);
        int ultPar_v = findUltimateParent(v);

        if (ultPar_u == ultPar_v) return;
        
        if (rank[ultPar_u] < rank[ultPar_v]){
            parent[ultPar_u] = ultPar_v;
        }
        else if (rank[ultPar_u] > rank[ultPar_v]){
            parent[ultPar_v] = ultPar_u;
        }
        else{ // Equal rank
            parent[ultPar_v] = ultPar_u;
            rank[ultPar_u]++;
        }
    }

    // -> Union by size
        // 1. Find ultimate parent of u and v : pu and pv
        // 2. find size of pu, pv
        // 3. Connect smaller size to larger size always

    void unionBySize(int u, int v){
        int ultPar_u = findUltimateParent(u);
        int ultPar_v = findUltimateParent(v);

        if (ultPar_u == ultPar_v) return;

        if (size[ultPar_u] < size[ultPar_v]){   
            parent[ultPar_u] = ultPar_v;
            size[ultPar_v] += size[ultPar_u];
        }
        else{
            parent[ultPar_v] = ultPar_u;
            size[ultPar_u] += size[ultPar_v];
        }
    }
};

int main(){
    int n; // No. of nodes
    cin>>n;

    DisjointSet ds(n); // Initialize

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Checking if 3 and 7 belong to the same component
    cout<<ds.isSameComponent(3, 7)<<endl; // 0
    
    ds.unionByRank(3, 7);
    cout<<ds.isSameComponent(3, 7)<<endl; // 1
    
    
    DisjointSet ds1(n); // Initialize

    ds1.unionBySize(1, 2);
    ds1.unionBySize(2, 3);
    ds1.unionBySize(4, 5);
    ds1.unionBySize(6, 7);
    ds1.unionBySize(5, 6);

    // Checking if 3 and 7 belong to the same component
    cout<<ds1.isSameComponent(3, 7)<<endl; // 0
    
    ds1.unionBySize(3, 7);
    cout<<ds1.isSameComponent(3, 7)<<endl; // 1
}

// It can be used when the graph is dynamically changing