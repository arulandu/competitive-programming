/*
Contest: Educational Codeforces Round 120 
Problem: [C] Set or Decrease
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n; ll k; cin >> n >> k;
  vector<ll> ar(n); for(int i = 0; i < n; i++) cin >> ar[i];
  
  sort(ar.begin(), ar.end());
  ll s = 0; for(auto x : ar) s += x;
  if(s <= k) return 0;

  // iterate through # of copy operations
  ll mn = LONG_LONG_MAX; s = k-s;
  for(int i = n; i > 0; i--){
    s += ar[i%n];
    ll q = floor(s*1.0L/(n-i+1LL)); // find greatest value
    ll r = max(ar[0]-q, 0LL)+(n-i); // # of decrease a[0] ops + copy to greatest i
    mn = min(r, mn);
  }

  return mn;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
