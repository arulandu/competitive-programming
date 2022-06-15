#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  ll k; cin >> k;
  ll x = ceil(sqrt(k));
  ll r = 1, c = x;
  ll q = k-(x-1)*(x-1);

  if(q <= x){
    r = q; c = x;
  } else {
    r = x; c = 2*x-q;
  }

  cout << r << ' ' << c << '\n';
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
