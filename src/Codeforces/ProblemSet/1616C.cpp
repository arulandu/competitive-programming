/*
Contest: Codeforces Good Bye 2021: 2022 is NEAR
Problem: [C] Representative Edges
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-6;

void solve(){
  int n; cin >> n;
  vector<int> ar(n); for(int i = 0; i < n; i++) cin >> ar[i];

  pair<int, pair<int, int>> bst = {INT_MAX, {-1, -1}};
  for(int l = 0; l < n; l++){
    for(int r = l; r < n; r++){
      // cout << l << ' ' << r << " | ";
      double d = r == l ? 0 : (ar[r]-ar[l])*1.0/(r-l);
      double a0 = ar[l]-l*d;
      // cout << d << ' ' << a0 << " ";
      int c = 0;
      for(int i = 0; i < n; i++){
        if(fabs((a0+i*d) - ar[i]) > EPS) c++;
      }
      // cout << c << '\n';
      if(c < bst.first){
        bst.first = c;
        bst.second = {l, r};
      }
    }
  }

  cout << bst.first << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
