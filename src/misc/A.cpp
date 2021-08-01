#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

/*
Use unordered_set (hash_set) for amortized O(1) insert and count time complexity.
Iterate through packages and insert. Iterate through packages and find the ideal number (space - 30 - x).
Check set for number and maximize the largest package in pair.

Time: O(n)
Space: O(n)
*/
pair<int, int> solve(int space, int count, const vector<int>& packages){
    unordered_set<int> s;
    
    for(auto x : packages){
        s.insert(x); // avg O(1)
    }

    pair<int, int> mxp = {-1, -1};
    int mx = INT_MIN;
    for(auto x : packages){
        int o = space - 30 - x;
        if(s.count(o) == 1){ // avg O(1)
            if(max(o, x) > mx){
                mxp = {x, o};
                mx = max(o, x);
            }
        }
    }
    if(mxp.first == -1 && mxp.second == -1) return mxp;

    pair<int, int> ind = {-1, -1};
    for(int i = 0; i < packages.size(); i++){
        if(ind.first < 0 && packages[i] == mxp.first) ind.first = i;
        if(ind.second < 0 && packages[i] == mxp.second) ind.second = i;
    }

    return ind;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  

  pair<int, int> ans = solve(90, 5, {1, 10, 25, 35, 60});
  cout << "<" << ans.first << ", " << ans.second << ">\n";
  return 0;
}
