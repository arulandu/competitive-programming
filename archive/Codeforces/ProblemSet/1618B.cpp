/*
Contest: Codeforces Round #760 (Div. 3)
Problem: [B] Missing Bigram
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<string> bis(n); for(int i = 0; i < n-2; i++) cin >> bis[i];

  // add letters one at a time
  string s = bis[0]; bool e = false;
  for(int i = 1; i < n-2; i++){
    if(bis[i][0] != s[s.size()-1]){
      s += bis[i]; e = true;
    } else {
      s += bis[i][1];
    }
  }

  // if no skips just pretend last was skipped
  if(!e) s += 'a';

  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
