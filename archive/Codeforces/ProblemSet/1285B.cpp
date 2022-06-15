#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n;
  vector<ll> a (n);
  ll tot = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    tot += a[i];
  }

  /*
  int dp0[i][j] = max subarray sum from 0 up to i (exclusive)
  i = index in [0, n-2]
  j = if max subarray ends at i-1
  */
  ll dp0[n][2];
  dp0[0][0] = 0; dp0[0][1] = 0;

  for(int i = 0; i < n-1; i++){
      dp0[i+1][1] = max(dp0[i][1]+a[i], a[i]);
      dp0[i+1][0] = max(dp0[i][1], dp0[i][0]); 
  }

  /*
  int dp1[i][j] = max subarray sum from 1 up to i (exclusive)
  i = index in [1, n-1]
  j = if max subarray ends at i-1
  */
  ll dp1[n+1][2];
  dp1[1][0] = 0; dp1[1][1] = 0;

  for(int i = 1; i < n; i++){
    dp1[i+1][1] = max(dp1[i][1]+a[i], a[i]);
    dp1[i+1][0] = max(dp1[i][1], dp1[i][0]); 
  }
  
  // use both dp's to avoid counting [1, n] subarray
  return tot > max(max(dp0[n-1][0], dp0[n-1][1]), max(dp1[n][0], dp1[n][1]));
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cout << (solve() ? "YES" : "NO") << '\n';
  }

  return 0;
}
