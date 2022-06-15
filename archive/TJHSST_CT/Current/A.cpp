#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

void solve(){
  string s; cin >> s;
  ld x, y; cin >> x >> y;
  ll r = sqrtl(x*x+y*y);
  // cout << x << ' ' << y << ' ' << r << '\n';
  cout << s[r%s.size()] << '\n';
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
