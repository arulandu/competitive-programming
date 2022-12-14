/*
Contest: Educational Codeforces Round 139
Problem: [C] Hamiltonian Wall
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int m; cin >> m;
  vector<vector<bool>> g(2, vector<bool>(m, false));
  for(int i = 0; i < 2; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      g[i][j] = (s[j] == 'B');
    }
  }
  
  vector<pair<int, int>> invs;
  for(int j = 0; j < m; j++){
    if(!g[0][j] && !g[1][j] && j != 0 && j != m-1) return false;
    int r = g[0][j] != g[1][j] ? (g[0][j] ? 1 : -1) : 0;
    if(r != 0){
      invs.push_back({j, r});
    }
  }

  // opposite inversions must be even apart and same side inversions must be odd apart
  for(int i = 1; i < invs.size(); i++){
    if(invs[i].second == invs[i-1].second && (invs[i].first-invs[i-1].first-1) % 2 == 1) return false;
    if(invs[i].second != invs[i-1].second && (invs[i].first-invs[i-1].first-1) % 2 == 0) return false;
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
