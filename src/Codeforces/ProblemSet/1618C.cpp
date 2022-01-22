/*
Contest: Codeforces Round #760 (Div. 3)
Problem: [C] Paint the Array
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll solve(){
  int n; cin >> n;
  vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i];

  // either even indices are red or odd indices are red.
  // choose d = gcd({}) and check if d divides a blue element
  ll g1 = a[0], g2 = a[1];
  for(int i = 0; i < n; i += 2) g1 = gcd(g1, a[i]);
  for(int i = 1; i < n; i += 2) g2 = gcd(g2, a[i]);

  bool gd = true;
  for(int i = 1; i < n; i += 2) {
    if(a[i] % g1 == 0) {
      gd = false; break;
    }
  }

  if(gd) return g1;
  
  gd = true;
  for(int i = 0; i < n; i += 2) {
    if(a[i] % g2 == 0) {
      gd = false; break;
    } 
  }

  if(gd) return g2;
  return 0;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
