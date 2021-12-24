#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vector<pair<ll, ll>> m(n); for(int i = 0; i < n; i++) cin >> m[i].second >> m[i].first;
  
  // choose earliest ending movie
  sort(m.begin(), m.end());
  int t = 0, c = 0;
  for(auto x : m){
    if(x.second < t) continue;
    t = x.first; c++;
  }
  
  cout << c << '\n';

  return 0;
}
