/*
Contest: Codeforces Round #559 (Div. 1)
Problem: [A] The Party and Sweets
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  // read input, sort increasing
  int n, m; cin >> n >> m;
  vector<ll> br(n), g(m); for(int i = 0; i < n; i++) cin >> br[i]; for(int i = 0; i < m; i++) cin >> g[i];
  sort(br.begin(), br.end());
  sort(g.begin(), g.end());

  ll s = 0; for(auto b : br) s += b; s *= m;
  if(br[n-1] > g[0]){
    cout << -1 << '\n'; // impossible if largest b val is greater than smallest g val
  } else {
    s += g[0] == br[n-1] ? 0 : g[0]-br[n-2]; // at lowest g val, if not alr satisfied, use second largest b vals
    for(int i = 1; i < m; i++) s += g[i]-br[n-1]; // for all else, adjust largest b val to match g vals
    cout << s << '\n';
  }

  return 0;
}
