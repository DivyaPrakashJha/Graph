#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;

bool visited[N];
vector<int> graph[N]; // Adjacency List

/*
// The dfs code can be divided into 4 sections : 

void dfs(int vertex){
    // 1. Take action on vertex after entering the vertex
    
    for(int child : graph[vertex]){
        // 2. Take action on child before entering the child node
        
        dfs(child);

        // 3. take action on child after exiting the child node
    }

    // 4. Take action on vertex before exiting the vertex
}
*/

void dfs(int vertex){
    cout<<vertex;
    visited[vertex] = 1;

    for(auto it : graph[vertex]){
        if (visited[it]) continue;
        dfs(it);
    }
}

// S.C. = O(V)
// T.C. = O(V+E)

int main(){
    int n, m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int v1, v2;
        cin>>v1>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);
}

// Sample Test Case
/*
7 8
1 4
1 6
1 5
4 5
5 7
5 2
2 3
3 7
*/