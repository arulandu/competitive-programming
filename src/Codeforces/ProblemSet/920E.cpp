/*
Contest: Educational Codeforces Round 37 [Rated for Div. 2]
Problem: [E] Connected Components
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m; cin >> n >> m;
  set<int> nadj[n]; // read not-edges
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;
    nadj[a].insert(b); nadj[b].insert(a);
  }

  set<int> uv; for(int i = 0; i < n; i++) uv.insert(i); // unvisited nodes

  function<int(int)> dfs = [&dfs, &uv, &nadj](int r) -> int {
    uv.erase(r);

    int c = 0;
    auto it = uv.begin();
    while(it != uv.end()){
      if(!nadj[r].count(*it)){
        int l = *it;
        c += dfs(l); // if r is connected to *it, dfs
        it = uv.upper_bound(l); // find next unvisited value (some vals >= l may've been erased in ^^ dfs call)
      } else {
        it++; // skip if r not connected to *it
      }
    }

    return c+1;
  };

  // run dfs to count components
  multiset<int> szs;
  for(int i = 0; i < n; i++) if(uv.count(i)) szs.insert(dfs(i));

  cout << szs.size() << '\n';
  for(auto sz : szs) cout << sz << ' '; cout << '\n';

  return 0;
}
