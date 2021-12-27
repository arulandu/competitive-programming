/*
Contest: Educational Codeforces Round 120 
Problem: [A] Construct a Rectangle
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll a, b, c; cin >> a >> b >> c;
  if(a == (b+c) || b == (a+c) || c == (a+b) || (c==b && a%2 == 0) || (a==b && c%2 == 0) || (a==c && b%2 == 0)){
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
