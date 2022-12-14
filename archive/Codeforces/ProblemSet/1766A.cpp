/*
Contest: Educational Codeforces Round 139
Problem: [A] Extremely Round
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  int s = 0;
  // count
  for(int x = 1; x <= 1e8; x*=10){
    s += min(9, n/x);
  }

  cout << s << "\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
