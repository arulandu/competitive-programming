/*
Contest: Educational Codeforces Round 134 (Div. 2)
Problem: [B] Deadly Laser
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, m, d;
  pair<int, int> s; 
  cin >> n >> m >> s.first >> s.second >> d;
  s.first--; s.second--;
  bool tr = min(s.first, m-s.second-1) > d;
  bool bl = min(n-s.first-1, s.second) > d;
  
  if(tr || bl){
    // go along border if not blocked
    cout << (n+m-2) << "\n";
  } else {
    cout << -1 << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
