#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9+7;
const ll MOD2 = 2*MOD;

// alternatively, force n to be in the second set (solve the problem for n-1) to avoid dividing by two
ll solve(){
  ll n; cin >> n;
  ll s = n*(n+1)/2;
  if(s % 2 == 1) return 0;
  s /= 2;

  ll dp[s+1]; for(ll i = 0; i <= s; i++) dp[i] = i == 0; 

  for(ll j = 1; j <= n; j++){
    for(ll i = s; i >= 1; i--){
      if(i-j >= 0) {
        dp[i] += dp[i-j];
        dp[i] %= MOD2;
      }
    }
  }

  return (dp[s]/2)%MOD;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  cout << solve() << '\n';

  return 0;
}
