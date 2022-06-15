/*
Contest: Educational Codeforces Round 93
Problem: [C] Good Subarrays
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  // read input, compute dp[i] = difference between current prefix sum and length of prefix
  int n; cin >> n; string s; cin >> s;
  ll dp[n]; for(int i = 0; i < n; i++) dp[i] = s[i]-'0' + (i > 0 ? dp[i-1] : 0)-1;

  // insight: any pair of i, j with dp[i]=dp[j] is valid. also if dp[i] = 0, i can = j
  map<ll, ll> m; // # of occurences for each dp[i] value
  for(int i = 0; i < n; i++) {
    if(!m.count(dp[i])) m[dp[i]] = 0;
    m[dp[i]]++;
  }

  ll c = 0;
  // for val = 0, n*(n+1)/2 otherwise (n-1)*n/2 subarrays
  for(auto p : m) {
    c += p.second*(p.second+(p.first == 0 ? 1 : -1))/2;
  }

  cout << c << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t; while(t--) solve();

  return 0;
}
