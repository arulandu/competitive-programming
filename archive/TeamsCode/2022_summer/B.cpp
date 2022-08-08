#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, q; cin >> n >> q;
  map<string, int> names;
  vector<int> acc(n, 100);
  vector<vector<pair<int, int>>> spends(n); // ind, amt
  for(int i = 0; i < q; i++){
    string name; int amt; cin >> name >> amt;
    if(names.count(name) == 0){
      names[name] = names.size();
    }

    spends[names[name]].push_back({i, amt});
    acc[names[name]] -= amt;
  }

  auto cmp = [](pair<int, int> &bst, pair<int, int> &item){
    return (item.first > bst.first || (item.first == bst.first && item.second < bst.second));
  };
  
  // for(auto x : acc) cout << x << ' '; cout << '\n';

  pair<int, pair<int, int>> lng = {-1, {-1, -1}}; 
  for(int i = 0; i < n; i++){
    // cout << i << " ||\n";
    pair<int, int> bstk = {-1, -1}; // length, start
    pair<int, int> stk = {0, -1};
    for(int j = 0; j <= spends[i].size(); j++){
      // cout << j << " stk " << stk.first << ' ' << stk.second << '\n';
      // if(j < spends[i].size()) cout << spends[i][j].first << ' ' << spends[i][j].second << '\n';

      // clear if consec chain is broken
      if(j == spends[i].size() || (j > 0 && spends[i][j].first != (spends[i][j-1].first+1))){
        if(cmp(bstk, stk)){
          bstk = stk;
        }
        stk = {0, -1};
      }

      // update streak
      if(j < spends[i].size()){
        if(stk.first == 0) stk.second = spends[i][j].first;
        stk.first++;
      }
    }

    if(cmp(lng.second, bstk)){
      lng = {i, bstk};
    }
    // cout << "bstk " << bstk.first << " " << bstk.second << '\n';
  }
  // cout << lng.first << " " << lng.second.first << ' ' << lng.second.second << '\n';
  int mx = -1e9, mn = 1e9;
  for(int i = 0; i < n; i++){
    if(i == lng.first) acc[i] -= lng.second.first*(n-1);
    else acc[i] += lng.second.first;
    mx = max(acc[i], mx);
    mn = min(acc[i], mn);
  }
  // for(auto x : acc) cout << x << ' '; cout << '\n';

  cout << (mx-mn) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
