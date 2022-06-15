/*
Contest: Codeforces Round #760 (Div. 3)
Problem: [A] Polycarp and Sums of Subsequences
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  // max = a+b+c, least two = a, b
  int n = 7;
  vector<ll> b(n); for(int i = 0; i < n; i++) cin >> b[i];
  sort(b.begin(), b.end());
  cout << b[0] << ' ' << b[1] << ' ' << b[n-1]-b[0]-b[1] << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
