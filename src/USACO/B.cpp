/*
Contest: USACO 2022 January Silver
Problem: [B]
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll n; cin >> n;
  vector<ll> v(n); for(ll i = 0; i< n; i++) cin >> v[i];
  map<ll, ll> ind; for(ll i = 0; i < n; i++) ind[v[i]] = i;

  ll sm = 0;
  set<ll> sn;
  for(int x = n; x >= 1; x--){
    if(sn.size() > 0){
      auto rit = sn.upper_bound(ind[x]), lit = sn.lower_bound(ind[x]);
      if(rit != sn.end()){
        // cout << ind[x] << ' ' << *rit << '\n';
        sm += *rit-ind[x]+1;
      }

      if(lit != sn.begin()){
        // cout << ind[x] << ' ' << *lit << "\n";
        lit--;
        sm += ind[x]-*lit+1;
      }
    }
    
    sn.insert(ind[x]);
  }

  
  cout << sm << '\n';

  return 0;
}
