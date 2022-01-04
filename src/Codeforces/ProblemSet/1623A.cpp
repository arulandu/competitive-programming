/*
Contest: Codeforces Round #763 [Div. 2]
Problem: [A] Robot Cleaner
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n, m; cin >> n >> m;
  pair<int, int> s, e; cin >> s.first >> s.second; cin >> e.first >> e.second;
  int mn = INT_MAX;
  if(e.second == s.second || e.first == s.first){
    return 0;
  }
  if(e.second >= s.second){
    mn = min(mn, e.second-s.second);
  } else {
    mn = min(mn, m-e.second+m-s.second);
  }
  if(e.first >= s.first){
    mn = min(mn, e.first-s.first);
  } else {
    mn = min(mn, n-e.first+n-s.first);
  }
  return mn;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
