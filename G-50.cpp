// Problem

// There are n stones at some integer coordinate points on a 2D plane.
// Each coordinate point may have at most one stone.
// You need to remove some stones.
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// Given an array stones of length n where stones[i] = [x_i, y_i] represents the location of the ith stone, 
// return the maximum possible number of stones that you can remove.

// Constraints:
// 1 <= stones.length <= 1000
// 0 <= xi, yi <= 10^4

// https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

#include<bits/stdc++.h>

using namespace std;

const int N = 10001;

class disjointSet{
    private:
        vector<int>parent, size;
    public:
        disjointSet(int n){
            parent.resize(n);
            size.resize(n, 1);

            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int getUltParent(int x){
            if (parent[x] == x) return x;

            return parent[x] = getUltParent(parent[x]);
        }

        void unionBySize(int x, int y){
            x = getUltParent(x);
            y = getUltParent(y);

            if (x == y) return;

            if (size[x] > size[y]){
                parent[y] = x;
                size[x] += size[y];
            }
            else{
                parent[x] = y;
                size[y] += size[x];
            }
        }
};

int main(){
    int n;
    cin>>n;

    // We group the stones into components according to the location they are at
    // In a component we can remove all the stones except one
    // Therefore ans = n - no. of components

    disjointSet ds(2*N + 10); // 0 to 10000 denotes rows and 10001 to rest denotes columns

    vector<pair<int, int>>stones(n);
    for(int i = 0, x, y; i < n; i++){
        cin>>x>>y;
        stones[i] = {x, y};

        int row = x;
        int col = N+y;
    
        ds.unionBySize(row, col); // Now the stones present in the row x and col y belong to the same component
    }

    set<int>ultParentofStone; // For counting how many unique parents are there for the stones i.e the number of components

    for(auto it : stones){
        ultParentofStone.insert(ds.getUltParent(it.first));
    }

    cout<<n - ultParentofStone.size();
}

// Sample Test Case

// 6
// 0 0
// 0 1
// 1 0
// 1 2
// 2 1
// 2 2

// 5
// 0 0
// 0 2
// 1 1
// 2 0
// 2 2

// Output

// 5
// 3