/*
Contests: Codeforces Global Round 19
Problem: [B] MEX and Array
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<ll> as(n); for(int i = 0; i < n; i++) cin >> as[i];

  ll sm = 0;
  for(ll l = 0; l < n; l++){
    ll c = 0;
    for(ll r = l; r < n; r++){
      c += as[r] == 0 ? 2 : 1;
      sm += c;
    }
  }
  
  cout << sm << "\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
