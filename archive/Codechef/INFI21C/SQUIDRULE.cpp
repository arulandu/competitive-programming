#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  int s = 0, mn = INT_MAX;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    s += x; mn = min(mn, x);
  }

  cout << (s-mn) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while(t--) solve();

  return 0;
}
