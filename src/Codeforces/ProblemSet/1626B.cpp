/*
Contest: Educational Codeforces Round 121
Problem: [B] Minor Reduction
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  string s; cin >> s;

  // if reduction can lead to double digit use left most such
  string bst = "";
  for(int i = s.size()-1; i >= 1; i--){
    int v = s[i-1]-'0'+s[i]-'0';
    if(v > 9){
      bst = s.substr(0, i-1)+(char)(v/10+'0')+""+(char)(v%10+'0')+s.substr(i+1);
      break;
    }
  }

  // otherwise use left most single digit replacement
  if(bst.size() == 0) bst = (char)(s[0]-'0'+s[1]-'0'+'0')+s.substr(2);

  cout << bst << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
