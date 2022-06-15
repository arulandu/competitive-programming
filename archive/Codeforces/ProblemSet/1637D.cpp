/*
Contests: Codeforces Global Round 19
Problem: [D] Yet Another Minimization Problem
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n; cin >> n;
  vector<int> as(n); for(int i = 0; i < n; i++) cin >> as[i];
  vector<int> bs(n); for(int i = 0; i < n; i++) cin >> bs[i];

  int mx = INT_MIN; for(auto a : as) mx = max(a, mx); for(auto b : bs) mx = max(b, mx);

  vector<bitset<10001>> dp(n); // dp[i][j] = if sum of j is possible with the first i elements of a
  int s = 0; for(auto a : as) s += a; for(auto b : bs) s += b;

  if(n == 1) return 0;

  for(int i = 0; i < n; i++) for(int j = 0; j <= mx*n; j++) if(i == 0 && j == as[i] || j == bs[i]) dp[i].set(j);

  for(int i = 1; i < n; i++){
    for(int j = 0; j <= mx*n; j++){
      // dp[i][j+(as[i] or bs[i])] is possible if dp[i-1][j] is possible
      if(dp[i-1].test(j)) {
        dp[i].set(j+as[i]); 
        dp[i].set(j+bs[i]);
      }
    }
  }

  int mn = INT_MAX;
  for(int j = mx*n; j >= 0; j--){
    // get best sum of squares of sums of as / bs
    if(dp[n-1].test(j)){
      mn = min(mn, j*j + (s-j)*(s-j));
    }
  }

  // sum = (n-2)*(a_0^2+...+a_{n-1}^2+b_0^2+...+b_{n-1}^2) + (a_0+...+a_{n-1})^2 + (b_0+...b_{n-1})^2
  int pd = 0; for(auto a : as) pd += a*a; for(auto b : bs) pd += b*b;
  return (n-2)*pd + mn;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}

