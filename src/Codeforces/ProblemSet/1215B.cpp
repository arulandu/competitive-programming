#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<bool> sg(n);
  for(int i = 0; i < n; i++){
    ll x; cin >> x;
    sg[i] = x > 0;
  }

  // dp[i][j] = # of segs ending at index i (inclusive) with product of sign pos / neg for j = 1 / 0
  ll dp[n][2]; 

  dp[0][1] = sg[0]; dp[0][0] = !sg[0];
  for(int i = 1; i < n; i++){
    dp[i][0] = (sg[i] ? dp[i-1][0] : dp[i-1][1]) + !sg[i];
    dp[i][1] = (sg[i] ? dp[i-1][1] : dp[i-1][0]) + sg[i];
  }
  
  // sum across all possible endings
  ll sp = 0, sn = 0;
  for(int i = 0; i < n; i++){
    sn += dp[i][0];
    sp += dp[i][1];
  }

  cout << sn << ' ' << sp << '\n';

  return 0;
}
