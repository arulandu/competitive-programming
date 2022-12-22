/*
Contest: Educational Codeforces Round 140 (Div. 2)
Problem: [D] Playoff
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;
  string s; cin >> s;
  ll one = 0; for(auto x : s) if(x == '1') one++;
  for(ll i = (1L << one); i <= (1L << n)-(1L << (n-one))+1; i++){
    cout << i << ' ';
  }
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
