/*
Contest: CodeChef Starters 70 Div. 3
Problem: Prime Reversal
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n; string a, b; cin >> a >> b;
  int a1 = 0, b1 = 0; 
  // check counts cuz X=2 is always possible
  for(int i = 0; i < n; i++){
    if(a[i] == '1') a1++;
    if(b[i] == '1') b1++;
  }

  cout << (a1 == b1 ? "YES" : "NO") << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
