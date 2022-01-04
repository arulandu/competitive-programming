#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, x; cin >> n >> x;
  vector<int> c(n); for(int i = 0; i < n; i++) cin >> c[i];
  int dp[x+1]; dp[0] = 0;
  for(int i = 1; i <= x; i++){
    dp[i] = INT_MAX;
    for(auto ci : c){
      if(ci <= i && dp[i-ci] != INT_MAX) dp[i] = min(dp[i], dp[i-ci]+1);
    }
  }

  cout << (dp[x] == INT_MAX || dp[x] == 0 ? -1 : dp[x]) << '\n';

  return 0;
}
