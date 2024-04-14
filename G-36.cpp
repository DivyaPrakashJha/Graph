// Problem

// Given start, end and an array arr of n numbers. 
// At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.
// Your task is to find the minimum steps in which end can be achieved starting from start. 
// If it is not possible to reach end, then return -1

// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include<bits/stdc++.h>

using namespace std;

#define inf 1e9

int main(){
    int st, end;
    cin>>st>>end;

    int n;
    cin>>n;

    vector<int>v(n);
    for(auto &it : v) cin>>it;

    vector<int>minSteps(100000, inf); // 0 to 99999 numbers possible since we mode by 100000
    // we just calculate the minimum no. of steps required to reach every possible number

    queue<pair<int, int>>q; // {Number, steps}

    q.push({st, 0});
    minSteps[st] = 0;

    while(!q.empty()){
        int num = q.front().first;
        int steps = q.front().second;

        q.pop();

        for(auto it : v){
            int newNum = (num * it)%100000;

            if (minSteps[newNum] > steps+1){
                minSteps[newNum] = steps+1;

                q.push({newNum, steps+1});
            }
        }
    }

    if (minSteps[end] == inf) cout<<-1;
    else cout<<minSteps[end];
}

// Sample Test Case

// 3 30
// 3
// 2 5 7

// 7 66175
// 3
// 3 4 65

// Output

// 2
// 4