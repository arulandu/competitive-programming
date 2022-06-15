/*
Contest: Educational Codeforces Round 122 (Div. 2)
Problem: [C] Kill the Monster
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  ll hc, dc, hm, dm, k, w, a; cin >> hc >> dc >> hm >> dm >> k >> w >> a;
  auto turn = [](ll h, ll d){
    return (h/d) + (h%d == 0 ? 0 : 1);
  };

  for(ll r = 0; r <= k; r++){
    if(turn(hc+r*a, dm) >= turn(hm, dc+(k-r)*w)){
      return true;
    }
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
