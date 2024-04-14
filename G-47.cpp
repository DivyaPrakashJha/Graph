// Problem

// Given a list of accounts where each element accounts [i] is a list of strings, 
// where the first element account [i][0]  is a name, and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. 
// Two accounts definitely belong to the same person if there is some common email to both accounts.
// Note that even if two accounts have the same name, they may belong to different people as people could have the same name.
// A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: 
// the first element of each account is the name, and the rest of the elements are emails in sorted order.

// Note: Accounts themselves can be returned in any order.

// https://practice.geeksforgeeks.org/problems/account-merge/1

#include<bits/stdc++.h>

using namespace std;

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

        vector<int> getComponents(){
            vector<int>x;

            for(int i = 0; i < parent.size(); i++){
                if (parent[i] == i) x.push_back(i);
            }

            return x;
        }
};

int main(){
    int n;
    cin>>n;

    vector<vector<string>>v;

    for(int i = 0; i < n; i++){
        int m;
        cin>>m;

        vector<string>x(m);
        for(auto &z : x) cin>>z;
        
        v.push_back(x);
    }

    // If any of the emails match then the two accounts is the same

    disjointSet ds(n);
    map<string, int>m; 

    for(int i = 0; i < n; i++){
        for(int j = 1; j < v[i].size(); j++){
            if (m.find(v[i][j]) == m.end()){
                m[v[i][j]] = i;
            }
            else{
                ds.unionBySize(i, m[v[i][j]]);
            }
        }
    }

    vector<string>temp[n];
    for(auto it : m){
        string email = it.first;
        int partOf = ds.getUltParent(it.second);

        temp[partOf].push_back(email);
    }

    vector<vector<string>>ans;

    for(int i = 0; i < n; i++){
        if(temp[i].size() != 0){
            sort(temp[i].begin(), temp[i].end());
            
            vector<string>x;
            x.push_back(v[i][0]);

            for(auto it : temp[i]){
                x.push_back(it);
            }

            ans.push_back(x);
        }
    }

    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<' ';
        }
        cout<<endl;
    }

}

// Sample Test Case

// 4
// 3
// John johnsmith@mail.com john_newyork@mail.com
// 3
// John johnsmith@mail.com john00@mail.com
// 2
// Mary mary@mail.com
// 2
// John johnnybravo@mail.com

// Output

// John john00@mail.com john_newyork@mail.com johnsmith@mail.com 
// Mary mary@mail.com 
// John johnnybravo@mail.com