// Problem

// There are a total of n tasks you have to pick, labeled from 0 to n-1.
// Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
// Given the total number of n tasks and a list of prerequisite pairs of size m.
// Find a ordering of tasks you should pick to finish all tasks.
// Note: There may be multiple correct orders, you just need to return one of them. 
// If it is impossible to finish all tasks, return an empty array.
// Returning any correct order will give the output as 1, whereas any invalid order will give the output O.

// We will use the Topological Sorting (Kahn's Algorithm) to generate the required order if possible

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>g(n);
    vector<int>indegree(n, 0);

    for(int i = 0, u, v; i < m; i++){
        cin>>v>>u;

        // To finish  task 'v' you have to first finish task 'u'
        // That means a directed edge from v to u

        g[u].push_back(v);
        indegree[v]++;
    }

    vector<int>visited(n, 0);
    queue<int>q;
    vector<int>topoSort;

    for(int i = 0; i < n; i++){
        if (indegree[i] == 0){
            q.push(i);
            topoSort.push_back(i);
            visited[i] = 1;
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto it : g[x]){
            if(!visited[it]){
                indegree[it]--;

                if (indegree[it] == 0){
                    q.push(it);
                    topoSort.push_back(it);
                    visited[it] = 1;
                }
            }
        }
    }

    if (topoSort.size() == n) cout<<"Yes\n";
    else cout<<"No\n";
    for (auto it : topoSort) cout<<it<<" ";
}

// Sample Test Case
// 8 11
// 0 2
// 1 0
// 1 2
// 3 1
// 3 4
// 2 4
// 5 4
// 3 5
// 7 5
// 6 7
// 6 3

// 8 11
// 0 2
// 1 0
// 2 1
// 3 1
// 3 4
// 2 4
// 5 4
// 3 5
// 7 5
// 6 7
// 6 3

// Output
// Yes
// 4 2 5 0 7 1 3 6

// No
// 4 5 7