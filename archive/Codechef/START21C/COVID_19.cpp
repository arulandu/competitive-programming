/*
Contest: CodeChef Starters 21 Division 3
Problem: [B] Covid and Theatre Tickets
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, m; cin >> n >> m;
  cout << ((n+1)/2)*((m+1)/2) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
