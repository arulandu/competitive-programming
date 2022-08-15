#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<ll> ans(n+1, 0); ans[1] = 0;
  for(ll i = 2; i <= n; i++){
    ans[i] = (i-1)*ans[i-1] + (i-2)*(i-2) + 1; // recursive definition
  }

  cout << ans[n] << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
