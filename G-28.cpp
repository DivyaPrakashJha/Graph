// Problem

// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. 
// Find the length of the shortest transformation sequence from startWord to targetWord.

// Keep the following conditions in mind:
// ->A word can only consist of lowercase characters.
// ->Only one letter can be changed in each transformation.
// ->Each transformed word must exist in the wordList including the targetWord.
// ->startWord may or may not be part of the wordList.

// https://practice.geeksforgeeks.org/problems/word-ladder/1

// We can use bfs to find the minimum length
// No. of words in list -> n
// Length of each word -> m

#include<bits/stdc++.h>

using namespace std;

#define inf INT_MAX

int main(){
    int n;
    cin>>n;

    vector<string>v(n);
    for(auto &x : v) cin>>x;

    int m = v[0].size();

    string startWord, targetWord;
    cin>>startWord>>targetWord;

    set<string>s;
    for(auto it : v) s.insert(it);
    
    queue<pair<string, int>>q;

    q.push({startWord, 0});
    s.erase(startWord);

    int ans = 0;
    while(!q.empty()){
        string x = q.front().first;
        int lev = q.front().second;

        if (x == targetWord){
            ans = lev+1;
            break;
        }

        q.pop();

        for(int i = 0; i < m; i++){
            for(char j = 'a'; j <= 'z'; j++){
                string y = x;

                y[i] = j;

                if (s.count(y)){
                    q.push({y, lev+1});
                    s.erase(y);
                }
            }
        }
    }

    cout<<ans;

}

// Sample Test Case

// 6
// hot dot dog lot log cog
// hit cog

// 5
// des der dfr dgt dfs 
// der dfs


// Output
// 5
// 3