/*
Contest: Educational Codeforces Round 122 (Div. 2)
Problem: [B] Minority
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  string s; cin >> s;
  int c1 = 0, c2 = 0;
  for(auto c : s) {
    if(c == '0'){
      c1++;
    } else if(c == '1'){
      c2++;
    }
  }

  int ot = 0;
  if(c1 == c2){
    int p1 = c1, p2 = c2;
    if(s[0] == '0'){
      p1--;
    } else {
      p2--;
    }

    if(p1 > 0 && p2 > 0 && p1 != p2) {
      ot = max(ot, min(p1, p2));
    }

    p1 = c2, p2 = c2;
    if(s[s.size()] == '0'){
      p1--;
    } else {
      p2--;
    }

    if(p1 > 0 && p2 > 0 && p1 != p2){
      ot = max(ot, min(p1, p2));
    }
  } else {
    ot = max(ot, min(c1, c2));
  }

  cout << ot << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
