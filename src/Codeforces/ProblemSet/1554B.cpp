#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  ll n, k; cin >> n >> k;
  vector<ll> v (n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  auto val = [&](int i, int j){
    return ((ll)i+1)*(j+1) - ((ll)k)*((ll)(v[i]|v[j]));
  };

  /*
  For i < n-100, val(n, j) >= val(i, j)
  Consider nj-100*(a[n]|a[j]) >= ij-100*(a[i]|a[j])
  => (n-i)j >= 100(a[n]|a[j]-a[i]|a[j])
  Bounding
  a[n]|a[j]-a[i]|a[j] <= a[n] <= n
  So, 
  (n-i)j >= 100n
  Maximizing, for j = n, i < n-100. So, any i < n-100 can be replaced with n.
  This turns the naive O(N^2) into O(100*N)
  */

  ll mx = LONG_LONG_MIN;
  for(ll j = n-1; j >= 0; j--){
    for(ll i = j-1; i >= max(0LL, n - 100); i--){
        mx = max(mx, val(i, j));
    }
    if(j != n-1) mx = max(mx, val(n-1, j));
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
