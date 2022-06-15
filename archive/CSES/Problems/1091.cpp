#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m; cin >> n >> m;
  multiset<ll> hs;
  for(int i = 0; i < n; i++) {ll h; cin >> h; hs.insert(h);}
  for(int i = 0; i < m; i++) {
    ll t; cin >> t;
    auto v = hs.upper_bound(t);
    if(v == hs.begin()){
      cout << -1 << '\n';
    } else {
      cout << *--v << '\n'; hs.erase(hs.find(*v));
    }
  }

  return 0;
}
