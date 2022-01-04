/*
Contest: USACO December Silver
Problem: [1] Switching on the Lights
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

const int ym[] = {1, -1, 0, 0};
const int xm[] = {0, 0, 1, -1};

const int MAXN = 102;
int n;
map<pair<int, int>, vector<pair<int, int>>> sw;
bool vis[MAXN][MAXN];
bool lt[MAXN][MAXN];

void dfs(int r, int c){
  if(r <= 0 || c <= 0 || r > n || c > n || !lt[r][c] || vis[r][c]) return;

  // visit and turn on all lights
  vis[r][c] = true;
  for(auto s : sw[{r, c}]) lt[s.first][s.second] = true;
  
  // check if turned on lights are now connected to visited component
  for(auto s : sw[{r, c}]) for(int i = 0; i < 4; i++) if(vis[s.first+ym[i]][s.second+xm[i]]) { dfs(s.first, s.second); break; }

  // flood
  for(int i = 0; i < 4; i++) dfs(r+ym[i], c+xm[i]);
}

int main(){
  io(true, "lightson");

  // build graph
  int m; cin >> n >> m; 
  for(int i = 0; i < m; i++){
    pair<int, int> a, b; cin >> a.first >> a.second >> b.first >> b.second;
    sw[a].push_back(b);
  }

  // init barn and dfs
  lt[1][1] = true; dfs(1, 1);

  // count lit
  int c = 0; for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(lt[i][j]) c++;
  cout << c << '\n';

  return 0;
}
