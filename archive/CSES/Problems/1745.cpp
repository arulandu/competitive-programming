#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXX = 1e3;
const int MAXN = 1e2;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vector<int> cs(n); for(int i = 0; i < n; i++) cin >> cs[i];
  
  bitset<MAXN*MAXX+1> dp = 1;
  for(auto c : cs){
    for(int i = n*MAXX; i >= 1; i--){
      if(i-c >= 0) dp[i] = dp[i] | dp[i-c];
    }
  }

  cout << dp.count()-1 << '\n';
  for(int i = 1; i <= n*MAXX; i++){
    if(dp[i]) cout << i << ' ';
  }
  cout << '\n';

  return 0;
}
