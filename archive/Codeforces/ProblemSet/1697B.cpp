/*
Contest: Educational Codeforces Round 130
Problem: [B] Promo
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n, q; cin >> n >> q;
  vector<ll> ps(n); for(ll i = 0; i < n; i++) cin >> ps[i];
  // prefix sums on descending
  sort(ps.begin(), ps.end(), greater<ll>());
  vector<ll> pf(n); for(ll i = 0; i < n; i++){ pf[i] = ps[i]; if(i > 0) pf[i] += pf[i-1]; }
  for(ll i = 0; i < q; i++){
    ll x, y; cin >> x >> y;
    ll s = pf[x-1]-(x-y-1 >= 0 ? pf[x-y-1] : 0);
    cout << s << "\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
