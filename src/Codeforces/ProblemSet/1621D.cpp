/*
Contest: Codeforces Hello 2022
Problem: [D] The Winter Hike
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll grid[500][500];
int n;

void solve(){
  cin >> n;
  for(int i = 0; i < 2*n; i++){
    for(int j = 0; j < 2*n; j++){
      cin >> grid[i][j];
    }
  }

  ll s = 0;
  // bottom-right quarter
  for(int i = n; i < 2*n; i++){
    for(int j = n; j < 2*n; j++){
      s += grid[i][j];
    }
  }

  // 1/8 corner squares is required
  s += min({grid[0][2*n-1], grid[2*n-1][0], grid[0][n], grid[n][0], grid[2*n-1][n-1], grid[n-1][2*n-1], grid[n][n-1], grid[n-1][n]});
  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
