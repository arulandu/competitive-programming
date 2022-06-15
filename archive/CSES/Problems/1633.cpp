#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  ll dp[n+1]; dp[0] = 1; for(int i = 1; i <= n; i++) dp[i] = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 1; j <= 6; j++){
      if(i+j <= n) {
        dp[i+j] += dp[i];
        dp[i+j] %= MOD;
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}
