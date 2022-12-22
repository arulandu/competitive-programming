/*
Contest: Educational Codeforces Round 140 (Div. 2)
Problem: [A] Cut the Triangle
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  pair<int, int> p1, p2, p3; cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
  bool x = p1.first == p2.first || p2.first == p3.first || p1.first == p3.first;
  bool y = p1.second == p2.second || p2.second == p3.second || p1.second == p3.second;
  cout << (x && y ? "NO" : "YES") << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
