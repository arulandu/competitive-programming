/*
Contest: USACO 2017 US Open Silver
Problem: #3 Where's Bessie?
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

const int MAXN = 20;
int grid[MAXN][MAXN];
int n;
int vis[MAXN][MAXN];

// iterative dfs flood fill - O(n^2)
int fill(int r, int c){
  stack<pair<int, int>> fringe;
  fringe.push({r, c});
  while(!fringe.empty()){
    auto v = fringe.top(); fringe.pop();
    if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= n || grid[v.first][v.second] != grid[r][c] || vis[v.first][v.second]){
      continue;
    }

    vis[v.first][v.second] = true;
    fringe.push({v.first+1, v.second}); fringe.push({v.first-1, v.second});
    fringe.push({v.first, v.second+1}); fringe.push({v.first, v.second-1});
  }

  return grid[r][c];
}

// flood fills components and checks condition
bool check(int lx, int rx, int uy, int dy){
  // reset vis
  for(int i = lx; i <= rx; i++){
    for(int j = uy; j <= dy; j++){
      vis[i][j] = false;
    }
  }

  // color components
  map<int, int> m;
  for(int i = lx; i <= rx; i++){
    for(int j = uy; j <= dy; j++){
      if(!vis[i][j]){
        int c = fill(i, j);
        if(!m.count(c)) m[c] = 0;
        m[c]++;
      }
    }
  }
  
  // check condition
  if(m.size() > 2) return false;
  int c1 = 0, c2p = 0;
  for(auto& p : m){
    if(p.second == 1) c1++;
    if(p.second >= 2) c2p++;
  }

  return c1 == 1 && c2p == 1;
}

// O(n^6+k^2) where there are k pcls ignoring the self-containing condition
int main(){
  io(true, "where");
  
  // read input as integers
  cin >> n;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++){
      grid[i][j] = s[j]-'A';
    }
  }

  // brute force all rects [O(n^4)]
  set<pair<pair<int, int>, pair<int, int>>> pcls;
  for(int lx = 0; lx < n; lx++){
    for(int rx = n-1; rx >= lx; rx--){
      for(int uy = 0; uy < n; uy++){
        for(int dy = n-1; dy >= uy; dy--){
          if(check(lx, rx, uy, dy)) pcls.insert({{lx, rx}, {uy, dy}});
        }
      }
    }
  }

  // count pcls that aren't contained by others - brute [O(pcl^2)]
  int pcl = 0;
  for(auto &p1 : pcls){
    bool val = true;
    for(auto &p2 : pcls){
      if(p1 != p2 && p2.first.first <= p1.first.first && p2.first.second >= p1.first.second && p2.second.first <= p1.second.first && p2.second.second >= p1.second.second){
        val = false; break;
      }
    }
    if(val){
      pcl++;
    }
  }

  cout << pcl << '\n';

  return 0;
}
