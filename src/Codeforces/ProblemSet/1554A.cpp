#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<ll> v (n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  /*
  Consider some l, r. adding r+1 can only increase max and decrease min.
  */
  pair<ll, ll> dp[n]; // max, min ending at i
  dp[1] = {max(v[0], v[1]), min(v[0], v[1])};
  for(int i = 2; i < n; i++){
    pair<ll, ll> pb = {max(v[i], dp[i-1].first), min(v[i], dp[i-1].second)}; // build
    pair<ll, ll> pn = {max(v[i], v[i-1]), min(v[i], v[i-1])}; // new
    if(pn.first*pn.second > pb.first * pb.second){
      dp[i] = pn;
    } else {
      dp[i] = pb;
    }
  }
  ll mx = -1;
  for(int i = 1; i < n; i++){
    // cout << "v: " << v[i] << " dp: " << dp[i].first << ' ' << dp[i].second << '\n';
    mx = max(dp[i].first*dp[i].second, mx);
  }

  cout << mx << '\n';
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
