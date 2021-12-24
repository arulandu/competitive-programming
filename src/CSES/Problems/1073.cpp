#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  multiset<ll> trs;
  for(int i = 0; i < n; i++){
    ll k; cin >> k;
    auto it = trs.upper_bound(k);
    if(it != trs.end()) trs.erase(trs.find(*it));
    trs.insert(k);
  }

  cout << trs.size() << '\n';

  return 0;
}
