/*
Contest: USACO 2019 December Silver
Problem: #3 Milk Visits
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

const int MAXN = 1e5+1;
int n, m;
vector<int> adj[MAXN];
bool val[MAXN]; // 0 if Guernsey and 1 if Holstein
int comp[MAXN];

// dfs color component
void dfs(int r, int c){
  stack<int> fringe;
  fringe.push(r);

  while(!fringe.empty()){
    auto v = fringe.top(); fringe.pop();
    if(v < 0 || v >= n || comp[v] != -1) continue;
    comp[v] = c;
    
    for(auto& p : adj[v]){
      if(val[v] == val[p])
        fringe.push(p);
    }
  }
}

int main(){
  io(true, "milkvisits");

  // input
  cin >> n >> m;
  string s; cin >> s;
  for(int i = 0; i < n; i++) val[i] = s[i] == 'G';
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b); adj[b].push_back(a);
  }

  // init color and use dfs to color components
  int c = -1;
  for(int i = 0; i < n; i++) comp[i] = c;
  for(int i = 0; i < n; i++){
    if(comp[i] == -1) dfs(i, ++c);
  }

  // a, b unsatisfied if and only if same component and component has opposite milk type
  for(int i = 0; i < m; i++){
    int a, b; char c; cin >> a >> b >> c; a--; b--;
    cout << ((comp[a] == comp[b] && val[a] != (c == 'G')) ? '0' : '1');
  }

  cout << '\n';

  return 0;
}
