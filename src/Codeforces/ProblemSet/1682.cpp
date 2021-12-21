#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  vector<int> g[n+1];
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
  }

  stack<int> s; s.push(1);
  set<int> vis;
  while(!s.empty()){
    int p = s.top(); s.pop();
    vis.insert(p);

    for(int j : g[p]){
      if(!vis.count(j)) s.push(j);
    }
  }

  if(vis.size() == n){
    cout << "YES\n";
  }
  for(int i = 1; i <= n; i++){
    if(!vis.count(i)){
      cout << "NO\n";
      cout << 1 << ' ' << i << '\n';
      break;
    }
  }
  return 0;
}