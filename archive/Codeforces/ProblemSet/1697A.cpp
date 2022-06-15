/*
Contest: Educational Codeforces Round 130
Problem: [A] Parkway Walk
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, m; cin >> n >> m;
  vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
  int s = 0; for(auto x : v) s += x;
  if(s >= m){
    cout << s-m << '\n';
  } else {
    cout << 0 << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
