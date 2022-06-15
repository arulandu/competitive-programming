/*
Contest: CodeChef Starters 21 Division 3
Problem: [G] The Melancholy of Problem Setter
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
bool solve(){
  int n; cin >> n;

  int val[n]; // B-0, G-1, R-2
  vector<vector<set<int>>> gs(3, vector<set<int>>(n, set<int>()));
  vector<vector<int>> comp(3, vector<int>(n, -1));
  
  // build full tree
  string s; cin >> s;
  for(int i = 0; i < n; i++) val[i] = s[i] == 'B' ? 0 : (s[i] == 'R' ? 2 : 1);
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b; a--; b--;
    gs[0][a].insert(b); gs[0][b].insert(a);
  }
  
  // root at first blue node
  int rt = -1; for(int i = 0; i < n; i++) if(val[i] == 0){ rt = i; break; }
  if(rt == -1) return true;

  // builds forest with only blue and kp colored nodes (removes everything else)
  function<void(int, int, int)> build = [&build, &gs, &val, &rt, &comp](int v, int pv, int kp){
    if(comp[kp][v] != -1) return; comp[kp][v] = 0;

    bool gd = val[v] == kp || val[v] == 0;
    if(pv != -1 && gd) gs[kp][pv].insert(v);

    for(auto nb : gs[0][v]) if(comp[kp][nb] == -1) build(nb, gd ? v : -1, kp);
  };

  // build blue-red and blue-green forest
  build(rt, -1, 2); build(rt, -1, 1);

  // finish bi-directional edges
  for(int i = 0; i < n; i++) for(int j = 1; j <= 2; j++) for(auto x : gs[j][i]) gs[j][x].insert(i);
  
  comp = vector<vector<int>>(3, vector<int>(n, -1));

  // dfs's connected component and counts # of blue nodes
  function<int(int, int, int)> cntb = [&cntb, &gs, &val, &rt, &comp](int v, int c, int kp){
    if(comp[kp][v] != -1) return 0; comp[kp][v] = c;

    int b = val[v] == 0 ? 1 : 0;
    for(auto nb : gs[kp][v]) if(comp[kp][nb] == -1) b += cntb(nb, c, kp);
    return b;
  };

  // label connected components and return false if more than 1 blue node in component
  int col = 0;
  for(int j = 1; j <= 2; j++) for(int i = 0; i < n; i++) if(comp[j][i] == -1) if(cntb(i, ++col, j) > 1) return false;

  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "Yes" : "No") << '\n';

  return 0;
}

/*
Insight:
If all blue nodes traverse at least 1 green/red node in simple path to another blue node, 
if all green nodes are deleted, each blue node must be in a separate component likewise if red is deleted.
This also applies to any number of colors, not just binary - red/green.
*/
