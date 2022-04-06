#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  vector<int> mn(4, INT_MAX);
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 4; j++){
      int x; cin >> x;
      mn[j] = min(mn[j], x);
    }
  }

  int s = 0; 
  for(int i = 0; i < 4; i++){
    if(mn[i] <= 0){
      cout << "IMPOSSIBLE\n"; return;
    }
    s += mn[i];
  }

  if(s < 1000000) {
    cout << "IMPOSSIBLE\n"; return;
  }
  s -= 1000000;

  for(int i = 0; i < 4; i++){
    if(s > 0) {
      int d = min(s, mn[i]);
      mn[i] -= d; s -= d;
    }
    cout << mn[i];
    if(i < 3) cout << " ";
    else cout << '\n';
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
