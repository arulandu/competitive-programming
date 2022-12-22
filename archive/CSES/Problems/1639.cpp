#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int inf = 1e9;

void solve(){
  string a, b; cin >> a >> b;
  vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, inf)); // min moves to change a[:i] into b[:k]
  dp[0][0] = 0;
  for(int i = 0; i <= a.size(); i++){
    for(int j = 0; j <= b.size(); j++){      
      // delete
      if(i > 0) dp[i][j] = min(dp[i][j], 1+dp[i-1][j]);
      if(j > 0) dp[i][j] = min(dp[i][j], 1+dp[i][j-1]);

      //swap
      if(i > 0 && j > 0) dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);

      // no change
      if(i > 0 && j > 0 && a[i-1] == b[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
    }
  }

  cout << dp[a.size()][b.size()] << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
