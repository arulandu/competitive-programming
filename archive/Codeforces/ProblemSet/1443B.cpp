#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int a, b; cin >> a >> b;
  string s; cin >> s;

  /*
    dp[i][j] = min number of coins to pay to remove all mines up to this point (exclusive)
    i = index
    j = 1 or 0 does a previous continuous activation line exist
  */
  ll dp[s.size()+1][2];

  dp[0][0] = 0; dp[0][1] = INT_MAX; // starting with activation is impossible
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '1'){
      dp[i+1][1] = min(dp[i][1], dp[i][0]+a); // line continues vs. start line
      dp[i+1][0] = INT_MAX; // impossible
    } else {
      dp[i+1][1] = min(dp[i][0]+a+b, dp[i][1]+b); // place and start line vs place and continue line
      dp[i+1][0] = min(dp[i][1], dp[i][0]); // do nothing
    }
  }

  cout << min(dp[s.size()][0], dp[s.size()][1]) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
