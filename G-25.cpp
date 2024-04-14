// Problem

// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
// Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order 
// and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

// Example:
// N = 5, K = 4
// dict = {"baa", "abcd", "abca", "cab", "cad"}

// b d a c

// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<string>dict(n);
    for(int i = 0; i < n; i++){
        cin>>dict[i];
    }

    // We can construct a directed graph from this data, and use topo sort to get the ordering

    vector<vector<int>>g(k);
    vector<int>indegree(k, 0);

    for(int i = 0; i < n-1; i++){
        string s = dict[i], t = dict[i+1];

        for(int j = 0; j < min(s.length(), t.length()); j++){
            if (s[j] != t[j]){
                // Means that character s[j] appears before t[j] in the alien dictionary
                // Implies a directed edge from char s[j] to char t[j]

                g[s[j]-'a'].push_back(t[j]-'a');
                indegree[t[j]-'a']++;

                break;
            }
        }
    }

    vector<int>visited(k, 0);
    queue<int>q;
    vector<char>ans;

    for(int i = 0; i < k; i++){
        if (indegree[i] == 0){
            q.push(i);
            ans.push_back(char('a'+i));
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto it : g[x]){
            if (!visited[it]){
                indegree[it]--;
                if (indegree[it] == 0){
                    q.push(it);
                    visited[it] = 1;
                    ans.push_back(char('a'+it));
                }
            }
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }

}

// Sample Test Case

// 5 4
// baa
// abcd
// abca
// cab
// cad

// 3 3
// caa
// aaa
// aab

// Output
// b d a c
// c a b