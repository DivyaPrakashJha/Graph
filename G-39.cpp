// Floyd Warshall Algorithm

// Multisource Shortest Path Algorithm
// It also helps to detect negative cycles

// If working with an undirected graph, we have to convert it into a directed graph i.e a-b become a->b and a<-b

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9

int main(){
    int n, m;
    cin>>n>>m;

    vector<pair<pair<int, int>, int>>edges; // {{u, v}, w}

    for(int i = 0, u, v, w; i < m; i++){
        cin>>u>>v>>w;

        edges.push_back({{u, v}, w});
    }

    // Converting the input to Adj Mat
    vector<vector<int>>cost(n, vector<int>(n, inf)); // All inf at start
    
    for(int i = 0; i < n; i++){
        cost[i][i] = 0;
    }

    for(auto it : edges){
        int x = it.first.first, y = it.first.second, w = it.second;

        cost[x][y] = w;
    }

    for(int k = 0; k < n; k++){ // Via Route ( i to j via k )
        // Updating the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (cost[i][k] != inf and cost[k][j] != inf){
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    // Output
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (cost[i][j] == inf) cout<<"inf ";
            else cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }

    // Detecting Negative Cycle

    // if cost[i][i] < 0 => Negative cycle exists
    for(int i = 0; i < n; i++){
        if (cost[i][i] < 0){
            cout<<"\nNegative cycle exists";
            return 0;
        }
    }

    cout<<"\nNegative cycle doesn't exist";
}


// T.C. - O(V^3)
// S.C. - O(V^2)

// Sample Test Cases

// 6 7
// 0 1 5
// 1 5 -3
// 1 2 -2
// 2 4 3
// 3 2 6
// 5 3 1
// 3 4 -2

// 6 7
// 0 1 5
// 1 5 -3
// 2 1 -2
// 2 4 3
// 3 2 1
// 5 3 1
// 3 4 -2

// Output

// 0 5 3 3 1 2
// inf 0 -2 -2 -4 -3
// inf inf 0 inf 3 inf
// inf inf 6 0 -2 inf
// inf inf inf inf 0 inf
// inf inf 7 1 -1 0

// Negative cycle doesn't exist


// 0 2 4 3 1 -1
// inf -3 -1 -2 -4 -6
// inf -5 -3 -4 -6 -8
// inf -4 -2 -3 -5 -7
// inf inf inf inf 0 inf
// inf -3 -1 -2 -4 -6

// Negative cycle exists
