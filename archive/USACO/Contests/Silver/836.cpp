/*
Contest: USACO 2018 US Open Silver
Problem: [3] Multiplayer Moo
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

const int MAXN = 252;
int n;

int grid[MAXN][MAXN];
int reg[MAXN][MAXN];

struct Reg {
  set<pair<int, int>> brd; // border cells of region
  set<int> nbs; // neighboring regions
  int s; // size
  int v; // grid value
};

map<int, Reg> regs; // component -> {{border}, size}

// label regions and count size
int dfs(int r, int c, int v){
  if(r <= 0 || r > n || c <= 0 || c > n || reg[r][c] != -1) return 0;

  int s = 1; reg[r][c] = v;

  bool br = false;
  for(int i = 0; i < 4; i++){
    if(grid[r+ym[i]][c+xm[i]] != grid[r][c]){
      br = true;
    } else {
      s += dfs(r+ym[i], c+xm[i], v);
    }
  }

  if(br) regs[v].brd.insert({r, c});
  return s;
}

int main(){
  io(true, "multimoo");
  
  cin >> n;
  for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) reg[i][j] = grid[i][j] = -1; 
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> grid[i][j];
  
  // find regions
  int c = -1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(reg[i][j] == -1){
        int s = dfs(i, j, ++c); 
        regs[c].s = s; regs[c].v = grid[i][j];
      }
    }
  }

  // update neighbor regions
  for(auto &rgp : regs){
    for(auto bd : rgp.second.brd){
      for(int i = 0; i < 4; i++){
        int nb = reg[bd.first+ym[i]][bd.second+xm[i]];
        if(nb != -1 && nb != rgp.first && !rgp.second.nbs.count(nb)) rgp.second.nbs.insert(nb);
      }
    }
  }

  int sngl = INT_MIN;
  int dbl = INT_MIN;
  set<pair<int, int>> mrgs; // merges that have been checked alr
  for(auto rgp : regs){
    sngl = max(sngl, rgp.second.s);
    
    // try to merge with neighbor
    for(auto mnb : rgp.second.nbs){
      if(mrgs.count({rgp.first, mnb}) || mrgs.count({mnb, rgp.first})) continue;

      // dfs through other regions that can be connected
      set<int> alw; alw.insert(regs[mnb].v); alw.insert(rgp.second.v);
      set<int> visc;
      stack<int> st; st.push(rgp.first);
      int s = 0;
      while(!st.empty()){
        auto p = st.top(); st.pop();
        if(visc.count(p)) continue;

        visc.insert(p); s += regs[p].s;
        for(auto nb : regs[p].nbs){
          if(!visc.count(nb) && alw.count(regs[nb].v)) {
            st.push(nb);
            mrgs.insert({p, nb}); // can skip this merge later
          }
        }
      }

      dbl = max(dbl, s);
    } 
  }

  cout << sngl << '\n';
  cout << dbl << '\n';
}
