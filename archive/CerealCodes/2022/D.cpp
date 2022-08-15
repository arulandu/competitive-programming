#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXB = 32;
const int inf = 1e9;

bool cb(ll n, int b){
  return ((n >> b) & 1LL) == 1LL;
}

// O(MAXB*N) => O(n*log(n))
ll solve(){
  int n, k; cin >> n >> k;
  vector<ll> c(n); for(int i =  0; i < n; i++) cin >> c[i];
  
  if(n == 1) return c[0];

  ll opt = 0;

  // O(n) check if >= o is attainable
  auto build = [&](ll o){
    int j = 0;
    ll s = 0;
    for(int i = 0; i < n && j < k; i++){
      s |= c[i];
      if((s&o) >= o){
        j++; s = 0;
      }
    }

    return j == k;
  };

  // build solution from MSB to LSB
  for(int b = MAXB; b >= 0; b--){
    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(cb(c[i], b)){
        cnt++;
      }
    }

    if(cnt >= k){
      ll popt = opt | (1LL << b);
      if(build(popt)) opt = popt;
    }
  }

  return opt;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) cout << solve() << "\n";

  return 0;
}
