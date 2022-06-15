#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll x; int n; cin >> x >> n;
  multiset<ll> ds; for(int i = 0; i < n; i++) {ll d; cin >> d; ds.insert(d); }

  ll c = 0;
  while(ds.size() > 1){
    auto l1 = ds.begin(), l2 = next(l1);
    c += *l1 + *l2; ds.insert(*l1 + *l2); ds.erase(l1); ds.erase(l2);
  }
  cout << c << '\n';

  return 0;
}
