#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll n, k; cin >> n >> k;
  vector<pair<ll, ll>> mvs(n);
  for(int i = 0; i < n; i++) {
    cin >> mvs[i].first >> mvs[i].second;
  }
  sort(mvs.begin(), mvs.end(), [](auto& m1, auto& m2){ return m1.second < m2.second; });

  multiset<ll> avs; for(int i = 0; i < k; i++) avs.insert(0);
  ll c = 0;
  for(int i = 0; i < n; i++){
    auto it = avs.upper_bound(mvs[i].first);
    if(it != avs.begin()){
      avs.erase(--it); avs.insert(mvs[i].second); c++;
    }
  }
  cout << c << '\n';

  return 0;
}
