// Problem

// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. 
// Find all shortest transformation sequence(s) from startWord to targetWord. 
// You can return them in any order possible.
// Keep the following conditions in mind:
// ->A word can only consist of lowercase characters.
// ->Only one letter can be changed in each transformation.
// ->Each transformed word must exist in the wordList including the targetWord.
// ->startWord may or may not be part of the wordList.
// ->Return an empty list if there is no such transformation sequence.

// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1


#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<string>v(n);
    for(auto &x : v) cin>>x;

    int m = v[0].size();

    string startWord, targetWord;
    cin>>startWord>>targetWord;

    vector<vector<string>>ans;

    set<string>s;
    for(auto it : v) s.insert(it);

    queue<vector<string>>q;
    q.push({startWord});

    int lev = 0;
    vector<string>usedOnLevel;
    usedOnLevel.push_back(startWord);

    while(!q.empty()){
        vector<string>seq = q.front();
        string word = seq.back();

        q.pop();
        
        if (seq.size() > lev){ 
            // We can't erase the element or mark the element as visited while inserting in the queue as it may be used multiple times in the same level 
            // For example : {rog->cog->dog} and {rog->log->dog} here dog is used multiple times
            // So as soon as we go to the next level we erase the elements used on the previous level
            lev++;
            for(auto it : usedOnLevel){
                s.erase(it);
            }
            usedOnLevel.clear();
        }

        if (word == targetWord){
            ans.push_back(seq);
            continue;
        }

        for(int i = 0; i < m; i++){
            for(char j = 'a'; j <= 'z'; j++){
                string y = word;

                y[i] = j;

                if (s.count(y)){
                    seq.push_back(y);
                    q.push(seq);
                    seq.pop_back();
                    usedOnLevel.push_back(y);
                }
            }
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

// 5
// des der dfr dgt dfs 
// der dfs

// 6
// hot dot dog lot log cog
// hit cog

// Output

// der dfr dfs 
// der des dfs

// hit hot dot dog cog 
// hit hot lot log cog