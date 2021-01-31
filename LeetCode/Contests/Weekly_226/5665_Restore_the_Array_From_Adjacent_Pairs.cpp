#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        map<int, vector<int>> m; // graph
        for(auto v : adjacentPairs){
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]);
        }
        vector<int> ar(n);
        for(auto p : m){
            if(p.second.size() == 1){
                ar[0] = p.first;
                break;
            }
        }
        ar[1] = m[ar[0]][0];
        for(int i = 2; i < n; i++){
            if(m[ar[i-1]][0] != ar[i-2]){
                ar[i] = m[ar[i-1]][0];
            } else {
                ar[i] = m[ar[i-1]][1];
            }
        }
        return ar;
    }
};