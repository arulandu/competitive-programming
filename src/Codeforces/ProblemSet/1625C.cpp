/*
Contest: Codeforces Round #765 (Div. 2)
Problem: [C] Road Optimization
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int inf = 1e9+1;

void solve(){
  int n, l, k; cin >> n >> l >> k;
  vector<int> ds(n+1); for(int i = 0; i < n; i++) cin >> ds[i];
  vector<int> as(n+1); for(int i = 0; i < n; i++) cin >> as[i];
  ds[n] = l; as[n] = 0; // let the end of the road be a speed limit of 0

  int dp[n+1][k+1]; // dp[i][j] = min drive time till ith speed limit (inclusive) with j removals
  
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= k; j++){
      dp[i][j] = (i == 0 && j == 0) ? 0 : inf;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= k; j++){
      if(dp[i][j] == inf) continue; // skip if not reachable

      // place next speed limit at position p (skipping limits in between)
      for(int p = i+1; p <= n; p++){
        int nk = j+p-i-1;
        if(nk <= k) dp[p][nk] = min(dp[p][nk], dp[i][j]+as[i]*(ds[p]-ds[i]));
      }
    }
  }

  int ans = INT_MAX;
  for(int j = 0; j < k+1; j++){
    ans = min(ans, dp[n][j]);
  }

  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();

  return 0;
}
