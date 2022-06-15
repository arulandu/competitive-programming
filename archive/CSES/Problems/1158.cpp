#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, x; cin >> n >> x;
  vector<pair<int, int>> bs(n);
  for(int i = 0; i < n; i++) cin >> bs[i].first;
  for(int i = 0; i < n; i++) cin >> bs[i].second;
  
  int dp[x+1]; for(int i = 0; i <= x; i++) dp[i] = 0;
  for(auto b : bs) for(int j = x; j >= 1; j--) if(j-b.first >= 0) dp[j] = max(dp[j], dp[j-b.first]+b.second);

  cout << dp[x] << '\n';

  return 0;
}
