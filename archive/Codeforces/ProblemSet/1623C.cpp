/*
Contest: Codeforces Round #763 [Div. 2]
Problem: [C] Balanced Stone Heaps
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<ll> hs(n); for(int i = 0; i < n; i++) cin >> hs[i];

  // check if min x is achievable
  auto f = [&](ll x) {
    // go reverse order and move all surplus / pile
    vector<ll> tmp(hs.begin(), hs.end());
    for(int i = n-1; i >= 2; i--){
      if(tmp[i] < x) return false;
      int r = min(hs[i], tmp[i]-x)/3;
      tmp[i] -= 3*r; tmp[i-1] += r; tmp[i-2] += 2*r;
    }
    return min(tmp[0], tmp[1]) >= x;
  };

  // binary search on ans (max)
  ll l = 0, r = 1e9;
  while(l < r){
    ll m = (l+r+1)/2;

    if(f(m)) {
      l = m; 
    } else {
      r = m-1;
    }
  }

  cout << l << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
