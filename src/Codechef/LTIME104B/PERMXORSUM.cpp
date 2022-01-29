/*
Contest: Codechef January Lunchtime 2022 Div. 2
Problem: [C] Permutation XOR Sum
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;
  vector<ll> v(n); for(ll i = 0; i < n; i++) v[i] = i+1;
  ll mb = 1 << (1+(ll)log2l(n)); 
  ll sm = 0;

  set<ll> ps;
  set<ll> inds; for(ll i = 1; i <= n; i++) inds.insert(i);
  
  // Observation (from brute force): each xor has value in form 2^n-1.
  for(ll j = mb; j > 0; j = j >> 1){
    set<ll> erinds;
    for(auto i : inds){
      ll o = i^(j-1);
      if(!ps.count(o) && o > 0 && o <= n){
        ps.insert(o);
        erinds.insert(i);
        sm += j-1;
      }

      if(j == 0) break;
    }

    for(auto er : erinds) inds.erase(er);
  }
  

  cout << sm << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
