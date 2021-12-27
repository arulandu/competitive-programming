/*
Contest: Codeforces Round #762 (Div. 3)
Problem: [B] Squares and Cubes
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;
  set<ll> s;
  for(int i = 1; i*i <= n; i++) s.insert(i*i);
  for(int i = 1; i*i*i <= n; i++) s.insert(i*i*i);
  cout << s.size() << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
