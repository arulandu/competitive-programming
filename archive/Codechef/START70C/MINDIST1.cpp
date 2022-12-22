/*
Contest: CodeChef Starters 70 Div. 3
Problem: Minimum distance between 1s
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  bool e = false, o = false;
  // shift by multiple of two so check by parity
  for(int i = 0; i < n; i++){
    if(s[i] == '1'){
      if(i%2 == 0) e = true;
      else o = true;
    }
  }

  cout << (e&&o ? 1 : 2) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
