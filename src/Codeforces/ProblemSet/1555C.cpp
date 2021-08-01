#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  ll m; cin >> m;
  vector<vector<ll>> a(2, vector<ll>(m));
  for(ll i = 0; i < 2; i++){
    for(ll j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  // prefix sums for top and bottom row
  ll pt[m], pb[m]; pt[0] = a[0][0]; pb[0] = a[1][0];
  for(int i = 1; i < m; i++){
    pt[i] = a[0][i]+pt[i-1];
    pb[i] = pb[i-1]+a[1][i];
  }

  // alice cuts down in one column (i). bob then can only get top suffix or bottom prefix.
  ll mn = LONG_LONG_MAX;
  for(ll i = 0; i < m; i++){
    mn = min(max(i > 0 ? pb[i-1] : 0, pt[m-1]-pt[i]), mn);
  }

  cout << mn << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
