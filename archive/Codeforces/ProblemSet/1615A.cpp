/*
Contest: Codeforces Global Round18
Problem: [A] Closing the Gap
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;
  vector<ll> v(n); for(ll i = 0; i < n; i++) cin >> v[i];
  ll s = 0; for(auto x: v) s += x;
  if(s % n > 0){
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
