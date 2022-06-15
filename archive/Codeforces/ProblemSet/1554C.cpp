#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  ll n, m; cin >> n >> m;
  ll ans = 0;

  // Build answer from most sig to least sig bit: O(log(n))
  for(int i = 63; i >= 0; i--){
    ll a = ans ^ n; // get target xor second value
    a &= (~0LL << i); // set lower bits to 0
    ll b = a + ((1LL << i) - 1LL); // set lower bits to 1
    ll taken = min(b, m)-a+1LL; // get # taken

    // set to 1 if all taken otherwise keep at 0
    if(taken == (1LL << i)){
      ans += (1LL << i); 
    }
  }

  cout << ans << '\n';
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
