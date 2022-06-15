#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  long double x = powl(0.143*n, n);

  cout << int(floorl(x)+(x-floorl(x) < 0.5 ? 0 : 1)) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
