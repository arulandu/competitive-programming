#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

ll solve(){
  ll n; cin >> n;
  if(n < 6) return 15;   // < 6, buy 6-slice pizza

  // any even >= 6 is exactly reachable. round up to even for odd >= 6. ratio is fixed at 2.5 min/slice regardless of pizza size.
  return (n%2 == 0 ? n : n+1)*5/2;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cout << solve() << '\n';
  }

  return 0;
}
