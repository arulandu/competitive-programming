/*
Contest: Codeforces Round #767 (Div. 2)
Problem: [B] GCD Arrays
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  ll l, r, k; cin >> l >> r >> k;
  
  // only one number
  if(l == r) return l > 1;
  
  // make everything even: operations = # odd numbers in [l, r]
  ll op = (r-l)/2;
  if(l%2 == 1 || r%2 == 1) op++;

  return op <= k;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
