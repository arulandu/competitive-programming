/*
Contest: Codechef January Lunchtime 2022 Div. 2
Problem: [B] Prefix Zeros
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n; ll k;

// is prefix zeroes from indices 0 to m work
bool ok(int m, vector<int> v) {
  int ops = 0;
  // backwards
  for(int i = m; i >= 0; i--){
    v[i] += ops;
    int tg = v[i] % 10 == 0 ? v[i] : 10*(1+v[i]/10);
    int op = tg-v[i];
    ops += op;
  }

  return ops <= k;
};

void solve(){
  cin >> n >> k;
  string s; cin >> s;
  vector<int> v(n); for(int i = 0; i < n; i++) v[i] = (s[i] == '0' ? 0 : s[i]-'0');

  // binary search on last index with zero
  int l = -1, r = n-1;
  while(l < r){
    int m = l + (r-l+1)/2;

    if(ok(m, v)){
      l = m;
    } else {
      r = m-1;
    }
  }

  cout << l+1 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
