#include <bits/stdc++.h>

using namespace std;
#define ll long long

/*
compute ideal row and column independently O(n^2) brute force
*/

pair<int, ll> opt(vector<ll> &v){
  // cout << "opt "; for(auto x : v) cout << x << " "; cout << '\n';
  pair<int, ll> res = {-1, 1e18};
  for(int i = 0; i < v.size(); i++){
    ll val = 0;
    for(int j = i-1; j >= 0; j--) val += v[j]*(i-j);
    for(int j = i+1; j <v.size(); j++) val += v[j]*(j-i);
    if(val < res.second){
      res = {i, val};
    }
  }

  return res;
}

void solve(){
  int n; cin >> n;
  vector<vector<ll>> grid(n, vector<ll>(n, 0));
  vector<ll> row(n, 0), col(n, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> grid[i][j];
      row[i] += grid[i][j];
      col[j] += grid[i][j];
    }
  }  
  
  pair<int, ll> opr = opt(row), opc = opt(col);
  // cout << opr.first << "," << opc.first << "\n";
  cout << opr.second+opc.second << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
