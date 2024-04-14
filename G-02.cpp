#include<bits/stdc++.h>

using namespace std;

// Generally graph input is given in the following manner 
// Suppose we have n nodes and m edges in the graph
// Then first line has the value of n and m
// The following m lines contains the information about edges
// i) If it is a non-weighted graph -> vertex1 vertex2 (Denoting an edge between vertex1 and vertex2)
// ii) If it a weighted graph -> vertex1 vertex2 weight (Denoting an edge between vertex1 and vertex2 having weight)

// // Graphs can be represented mainly in two ways :
// 1. Adjacency Matrix
// 2. Adjacency List

// No. of vertices in the graph = N
// No. of edges in the graph = M

// // 1. Adjacency Matrix
// Space Complexity = O(N*N)

// i) Non-Weighted Graph

// Initialise : Graph[N][N]
// Graph[i][j] = 1 - if an edge is present between i and j
// Graph[i][j] = 0 - if no edge is present between i and j

// ii) Weighted Graph

// Initialise : Graph[N][N]
// Graph[i][j] = weight - if an edge is present between i and j having weight
// Graph[i][j] = 0 - if no edge is present between i and j


// // 2. Adjacency List
// Space Complexity = O(N+M)

// i) Non-Weighted Graph

// Initialise : vector<int> Graph[N] (Array of vectors)
// The vector Graph[i] contains all the vertices which have an edge with the ith vertex

// ii) Weighted Graph

// Initialise : vector< pair<int, int> > Graph[N];
// The vector Graph[i] contain all the vertices which have an edge with the ith vertex with their weights

int main(){
    int n = 5, m = 7;

    // // Non-Weighted Graph
    
    vector<pair<int, int>>edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}, {3, 5}, {4, 5}};
    
    // Adjacency Matrix
    int Graph[n+1][n+1] = {0};
    for(auto it : edges){
        Graph[it.first][it.second] = 1;
        Graph[it.second][it.first] = 1; // As it is an undirected graph
    }

    // Adjacency List
    vector<int> Graph1[n+1];
    for(auto it : edges){
        Graph1[it.first].push_back(it.second);
        Graph1[it.second].push_back(it.first);
    }

    
    // // Weighted Graph

    vector< pair< pair<int, int>, int > >edges1 = {{{1, 2}, 4}, {{2, 3}, 3}, {{3, 4}, 9}, {{4, 1}, 3}, {{1, 5}, 1}, {{3, 5}, 7}, {{4, 5}, 8}};

    // Adjacency Matrix
    int Graph2[n+1][n+1] = {0};

    for(auto it : edges1){
        Graph2[it.first.first][it.first.second] = it.second;
        Graph2[it.first.second][it.first.first] = it.second;
    }

    // Adjacency List
    vector<pair<int, int>> Graph3[n+1];

    for(auto it : edges1){
        Graph3[it.first.first].push_back({it.first.second, it.second});
        Graph3[it.first.second].push_back({it.first.first, it.second});
    }


    // Output

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(auto it : Graph1){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<Graph2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    for(auto it : Graph3){
        for(auto it1 : it){
            cout<<it1.first<<"-"<<it1.second<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}