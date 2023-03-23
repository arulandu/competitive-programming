/*
Contest: Educational Codeforces Round 145 
Problem: [B] Points on Plane
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// 2k^2+2k+1

ll f(ll x){
  // cout << "f: " << x << "\n";
  return (x+1LL)*(x+1LL);
}

void solve(){
  ll n; cin >> n;
  if(n == 1) {
    cout << 0 << '\n'; return;
  }

  ll l = 0;
  ll r = 1e9;
  while(l < r){
    // cout << l << ' ' << r << '\n';
    ll m = (l+r)/2LL;
    if(f(m) >= n) {
      // cout << "left\n";
      r = m;
    } else {
      // cout << "right\n";
      l = m+1LL;
    }
  }

  cout << l << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
