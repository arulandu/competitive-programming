#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int r, c; cin >> r >> c;
  auto brd = [&](int ri){
    for(int i = 0; i < 2*c+1; i++){
      if(ri == 0 && i < 2) cout << '.';
      else cout << (i%2 == 0 ? '+' : '-');
    }
    cout << '\n';
  };
  for(int i = 0; i < r; i++){
    brd(i);
    for(int j = 0; j < 2*c+1; j++){
      cout << (j%2 == 1 || (i == 0 && j == 0) ? '.' : '|');
    }
    cout << '\n';
  }
  brd(-1);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ":" << '\n';
    solve();
  }

  return 0;
}
