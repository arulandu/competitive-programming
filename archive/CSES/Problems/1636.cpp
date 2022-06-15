#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, x; cin >> n >> x;
  vector<int> cs(n); for(int i = 0; i < n; i++) cin >> cs[i];
  sort(cs.begin(), cs.end());

  int dp[x+1]; dp[0] = 1; for(int i = 1; i <= x; i++) dp[i] = 0;
  for(auto c : cs){
    for(int i = 1; i <= x; i++){
      if(i-c >= 0){
        dp[i] += dp[i-c];
        dp[i] %= MOD;
      }
    }
  }

  cout << dp[x] << '\n';

  return 0;
}
