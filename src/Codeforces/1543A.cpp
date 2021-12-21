#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  ll a, b; cin >> a >> b;
  ll e = abs(a-b);
  ll m = (ceil(e/min(a, b))-1)*min(a, b);
  cout << e << ' ' << m << '\n';
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
