/*
Contest: Educational Codeforces Round 137 (Rated for Div. 2)
Problem: [A] Password
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> ds(n); for(int i = 0; i < n; i++) cin >> ds[i];
  cout << (6*(10-n)*(9-n)/2) << "\n";  // 4C2*(10-n)C2
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
