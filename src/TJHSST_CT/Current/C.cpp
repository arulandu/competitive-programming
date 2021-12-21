#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  vector<ll> v(n);
  for(ll i = 0; i < n; i++){
    cin >> v[i];
  }

  ll dp[n]; // ending at i always end w - and start w +
  dp[0] = 0;
  for(ll i = 1; i < n; i++){
    dp[i] = max(i > 1 ? dp[i-2] : 0LL, 0LL)+v[i-1]-v[i];
  }

  ll m = dp[1];
  for(ll i = 1; i < n; i++){
    m = max(dp[i], m);
  }

  cout << m << '\n';

  return 0;
}
