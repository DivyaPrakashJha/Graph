#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;

bool visited[N];
vector<int> graph[N]; // Adjacency List

// Breadth first search or level order treaversal

void bfs(int source){
    queue<int>q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()){
        int t = q.front();
        cout<<t<<' ';
        q.pop();
        
        for(auto it : graph[t]){
            if (!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}

// S.C. = O(V+E) 
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

    bfs(1);
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