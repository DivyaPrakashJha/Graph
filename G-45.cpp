// Problem

// Given an undirected graph with V vertices. 
// We say two vertices u and v belong to a single province if there is a path from u to v or v to u. 
// Your task is to find the number of provinces.

// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

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
        
        int count(){
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

    for(int i = 0, u, v; i < m; i++){
        cin>>u>>v;
        ds.unionBySize(u, v);
    }

    cout<<ds.count();
}

// Sample Test Case
// 4 2
// 1 2
// 3 0

// Output
// 2