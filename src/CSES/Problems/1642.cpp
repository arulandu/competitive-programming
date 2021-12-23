#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; ll x; cin >> n >> x;
  vector<ll> v(n); for(int i = 0; i < n; i++) cin >> v[i];
  map<ll, set<pair<int, int>>> prs; // 2 element sum -> set(pairs of indices)
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      prs[v[i]+v[j]].insert({i, j});
    }
  }

  // find two disjoint pairs that sum to ox
  for(auto pr : prs){
    ll o = x-pr.first; pair<int, int> fp = *pr.second.begin(), op = {-1, -1};
    if(prs.count(o) && prs[o].size() > 0){
      auto opr = *prs.find(o);
      auto it = opr.second.begin();
      if(o == pr.first){
        if(opr.second.size() < 2) continue;
        it++;
      }

      // continue iterating until disjoin
      while(it != opr.second.end() && (it->first == fp.first || it->first == fp.second || it->second == fp.first || it->second == fp.second)) it++;

      if(it == opr.second.end()) continue;
      op = *it;
    }

    if(op.first >= 0){
      cout << fp.first+1 << ' ' << fp.second+1 << ' ' << op.first+1 << ' ' << op.second+1 << '\n';
      return 0;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
