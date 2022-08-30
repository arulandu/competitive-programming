/*
Contest: 2022 Facebook Hacker Cup Qualification Round
Problem: [B1] Second Friend 
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, m; cin >> n >> m;
  bool grid[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char x; cin >> x;
      grid[i][j] = x == '^';
    }
  }
  // check size is 1
  if(n <= 1 || m <= 1){
    // yes if no trees
    bool t = false; for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) t |= grid[i][j];
    if(t) {
      cout << "Impossible\n"; return; 
    }
  } else {
    // fill all
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        grid[i][j] = true;
      }
    }
  }

  cout << "Possible\n";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << (grid[i][j] ? '^' : '.');
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
