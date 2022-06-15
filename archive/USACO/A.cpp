/*
Contest: USACO 2022 January Silver
Problem: [A]
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<pair<ll, ll>, ll> dp;
ll dist(ll a, ll b){
  if(dp.count({a, b}) > 0) return dp[{a, b}];
  
  ll d = 0;
  if(a > 1 && a % 2 == 1) {
    d++; a++;
  }
  if(b > 1 && b % 2 == 1){
    d++; b--;
  }
  if(d > 0) {
    d += dist(a, b);
  } else {
    d = LONG_LONG_MAX;
    if(a <= b) d = min(d, b-a);
    if(b % 2 == 0) d = min(d, 1+dist(a, b/2));
    if(a % 2 == 0) d = min(d, 1+dist(a/2, b));
  }

  // cout << "d: " << a << ' ' << b << ' ' << d << '\n';
  dp[{a, b}] = d;
  return d;
}

void solve(){
  dp.clear();
  ll a, b; cin >> a >> b;
  cout << dist(a, b) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
