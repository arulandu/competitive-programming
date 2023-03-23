/*
Contest: Educational Codeforces Round 145 
Problem: [A] Garland
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  string s; cin >> s;
  map<char, int> mp; 
  for(auto c : s){
    if(mp.count(c) == 0) mp[c] = 0;
    mp[c]++;
  }

  if(mp.size() == 1) return -1;
  if(mp.size() == 4) return 4;

  for(auto p : mp){
    if(p.second == 3) return 6;
  }

  return 4;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
