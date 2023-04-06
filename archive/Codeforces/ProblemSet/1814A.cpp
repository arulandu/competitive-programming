/*
Contest: Educational Codeforces Round 146 
Problem: [A] Coins
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  ll n, k; cin >> n >> k;
  if(n%2 == 0) return true;
  if(k%2 == 0) return false;
  if(n>=k) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}
