/*
Contest: Codeforces Good Bye 2021: 2022 is NEAR
Problem: [B] Mirror in the String
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; string s; cin >> n >> s;
  int k = 0;
  while(k < n-1){
    if(s[k+1] > s[k] || (k == 0 && s[k+1] == s[k])){
      break;
    }
    k++;
  }

  string o = s.substr(0, k+1);
  for(int i = k; i >= 0; i--){
    o += s[i];
  }

  cout << o << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
