/*
Contest: Educational Codeforces Round 140 (Div. 2)
Problem: [B] Block Towers
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<ll> as(n); for(int i = 0; i < n; i++) cin >> as[i];
  sort(++as.begin(), as.end());
  for(int i = 1; i < n; i++){
    if(as[i] <= as[0]) continue;
    int d = (as[i]-as[0]+1)/2;
    as[0] += d; as[i] -= d;
  }
  cout << as[0] << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
