/*
Contest: 2022 Facebook Hacker Cup Qualification Round
Problem: [A] Second Hands
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n, k; cin >> n >> k;
  vector<int> s(n); for(int i = 0; i < n; i++) cin >> s[i];
  map<int, int> m;
  for(auto x : s){
    if(m.count(x) == 0)m[x] = 0;
    m[x]++;
  }

  // split one per each
  int c1 = 0, c2 = 0;
  for(auto p : m){
    if(p.second > 2) return false; // can't have more than 1
    for(int i = 0; i < p.second; i++){
      if(c1 <= c2) c1++;
      else c2++;
    }
  }

  // check size
  return c1 <= k && c2 <= k;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    cout << (solve() ? "YES" : "NO") << '\n';
  }

  return 0;
}
