#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll x; int n; cin >> x >> n;
  set<ll> lts; multiset<ll> sts;
  lts.insert(0); lts.insert(x); sts.insert(x);
  
  for(int i = 0; i < n; i++){
    ll p; cin >> p; 
    ll l = *--lts.lower_bound(p), r = *lts.upper_bound(p);
    lts.insert(p); sts.erase(sts.find(r-l)); sts.insert(p-l); sts.insert(r-p);
    cout << *--sts.end() << ' ';
  }
  cout << '\n';

  return 0;
}
