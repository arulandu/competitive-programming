/*
Contest: Codeforces Round #761 (Div. 2)
Problem: [B] GCD Problem
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;

  if(n % 2 == 0){
    cout << n-3 << ' ' << 2 << " " << 1 << '\n';
  } else {
    int k = (n-1)/2;
    if(k % 2 == 0){
      cout << k-1 << ' ' << k+1 << ' ' << 1 << '\n';
    } else {
      cout << k-2 << ' ' << k+2 << ' ' << 1 << "\n";
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
