/*
Contest: Educational Codeforces Round 122 (Div. 2)
Problem: [A] Div. 7
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  int x = 7*(n/7);
  if((x/10) != (n/10)) x += 7;
  cout << x << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
