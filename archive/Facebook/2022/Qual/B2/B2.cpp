/*
Contest: 2022 Facebook Hacker Cup Qualification Round
Problem: [B2] Second Second Friend 
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<int, int>> deltas = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){
  int n, m; cin >> n >> m;
  vector<vector<char>> igrid(n, vector<char>(m)), grid(n, vector<char>(m));

  // fill all trees
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> igrid[i][j];
      grid[i][j] = igrid[i][j];
      if(grid[i][j] == '.') grid[i][j] = '^';
    }
  }
  
  // count neighbors
  auto nbs = [&](int r, int c){
    int num = 0;
    for(auto d : deltas){
      int nr = r + d.first, nc = c+d.second;
      if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '^'){
        num++;
      }
    }
    return num;
  };

  // flood fill delete trees with 1 neighbor
  stack<pair<int, int>> st;
  auto flood = [&](int r, int c){
    st.push({r, c});
    while(!st.empty()){
      auto v = st.top(); st.pop();
      if(igrid[v.first][v.second] == '^'){
        cout << "Impossible\n"; return false;
      }
      grid[v.first][v.second] = '.';
      for(auto d : deltas){
        int nr = v.first + d.first, nc = v.second +d.second;
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '^' && nbs(nr, nc) < 2){
          st.push({nr, nc});
        }
      }
    }

    return true;
  };

  // go through all and dfs
  for(int rep = 0; rep < 2; rep++){
    for(int r = 0; r < n; r++){
      for(int c = 0; c < m; c++){
        if(grid[r][c] == '^' && nbs(r, c) < 2){
          assert(rep < 1);
          if(!flood(r, c)) return;       
        }
      }
    }
  }

  // print
  cout << "Possible\n";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << grid[i][j];
    }
    cout << '\n';
  }
  
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
