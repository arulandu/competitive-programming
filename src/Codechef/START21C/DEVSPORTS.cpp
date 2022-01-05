/*
Contest: CodeChef Starters 21 Division 3
Problem: [A] Devendra and Water Sports
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int z, y, a, b, c; cin >> z >> y >> a >> b >> c;
  cout << (z-y >= a+b+c ? "YES" : "NO") << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
