#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;

  bool g[2][n];
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      char c; cin >> c;
      g[i][j] = c == '1';
    }
  }

  // greedily check from left diagonal to center to right diagonal
  int s = 0; bool l = false, c = true, r = true;
  for(int i = 0; i < n; i++){
    if(g[1][i]){
      if(l && g[0][i-1]){
        s++;
      } else if(c && !g[0][i]){
        s++;
        c = false;
      } else if(r && g[0][i+1]){
        s++;
        r = false;
      }
    }

    l = c; c = r; r = i < n - 2;
  }

  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
