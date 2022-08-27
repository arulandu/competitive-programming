/*
Contest: Codeforces Round #816 (Div.2)
Problem: [B] Beautiful Array
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// O(n)
void solve(){
  // init
  ll n, k, b, s; cin >> n >> k >> b >> s;
  vector<ll> a(n, 0);

  // reduce from sum and update array
  auto add = [&a, &s](ll i, ll x){
    a[i] += x;
    s -= x;
  };

  // make b using first term
  add(0, b*k); if(s < 0){cout << -1 << '\n'; return;}

  // fill rest with 0 beauty (max k-1)
  for(int i = 0; i < n && s > 0; i++){
    ll x = min(s, k-1);
    add(i, x);
  }

  // answer
  if(s > 0){cout << -1 << '\n'; return;}
  for(auto x : a) cout << x << ' '; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
