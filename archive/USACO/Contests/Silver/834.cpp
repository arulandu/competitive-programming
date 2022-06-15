/*
Contest: USACO 2018 US Open Contest Silver
Problem: #1 Out of Sorts
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

int main(){
  io(true, "sort");

  int n; cin >> n;
  vector<int> ar(n);
  for(int i = 0; i < n; i++) cin >> ar[i];

  vector<int> s(ar.begin(), ar.end());
  sort(s.begin(), s.end());

  map<int, vector<int>> m; // val : occurrences in sorted seq. in descending order
  for(int i = n-1; i >= 0; i--){
    if(!m.count(s[i])) m[s[i]] = vector<int>();
    m[s[i]].push_back(i);
  }
  

  int moo = -1;
  for(int i = 0; i < n; i++){
    // ar[i] with least i goes to m[ar[i]] with least i
    int v = i-m[ar[i]][m[ar[i]].size()-1]; // displacement
    moo = max(v, moo); // max pos displacement decreases by 1 every sort iter.
    m[ar[i]].pop_back();
  }

  // check if sorted pass (+1)
  cout << moo+1 << '\n';

  return 0;
}
