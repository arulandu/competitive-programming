#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll sus(ll x){
  ll s = 0;
  while(x > 0){
    s += x%10;
    x /= 10;
  }
  return s%13;
}

void solve(){
  int n, m; cin >> n >> m;
  vector<ll> ids(n); for(int i = 0; i < n; i++) cin >> ids[i];
  sort(ids.begin(), ids.end(), [](auto &id1, auto &id2){
    ll s1 = sus(id1), s2 = sus(id2);
    if(s1 == s2){
      return id1 > id2;
    }

    return s1 > s2;
  });
  for(int i = 0; i < m; i++) cout << ids[i] << '\n';
} 

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
