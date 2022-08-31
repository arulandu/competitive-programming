/*
Contest: Codechef Starters 54 (Div. 3)
Problem: [A] Ticket Fine
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int x, p, q; cin >> x >> p >> q;
  cout << x*max((p-q), 0) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
