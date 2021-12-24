#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vector<pair<ll, ll>> ts(n); for(int i = 0; i < n; i++) cin >> ts[i].first >> ts[i].second;
  sort(ts.begin(), ts.end());
  ll t = 0, r = 0;
  for(auto& s : ts){ t += s.first; r += s.second-t; }
  cout << r << '\n';
  return 0;
}
