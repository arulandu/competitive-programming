/*
Contest: Codeforces Round #816 (Div.2)
Problem: [A] Crossmarket
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, m; cin >> n >> m;
  int s;
  if(n == 1 && m == 1) s = 0;
  else if(m > n) s = 2*n+m-2;
  else s = 2*m+n-2;
  cout << s << "\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
