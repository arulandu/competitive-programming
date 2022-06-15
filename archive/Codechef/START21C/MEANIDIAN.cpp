/*
Contest: CodeChef Starters 21 Division 3
Problem: [F] Mean equals Median
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll solve(){
  ll n; cin >> n;
  vector<ll> as(n); for(ll i = 0; i< n; i++) cin >> as[i];
  sort(as.begin(), as.end());
  ll s = 0; for(auto x : as) s += x; ll os = s;

  // increase median until >= mean
  ll q = 0; ll m = (n-1)/2;
  while(n*as[m] < s){
    while(m+q < n && as[m] == as[m+q]) q++; // move m+q to index after last element equal to median
    ll r = min(q < n ? as[m+q] : LONG_LONG_MAX, s/n + (s % n == 0 ? 0 : 1))-as[m]; // increase till next q change or s
    as[m] += r; s += q*r; // increment entire median block
  }

  // increase largest element until mean = median
  s += n*as[m]-s;

  // monovariant: sum increases by 1 every operation so # of ops = sum - original sum
  return s-os;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
