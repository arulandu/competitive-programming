/*
Contest: Educational Codeforces Round 139
Problem: [B] Notepad#
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n; string s; cin >> s;
  multiset<string> st; // check pairs
  for(int i = 1; i < n; i++){
    string nxt = ""; nxt += s[i-1]; nxt += s[i];
    if(st.count(nxt) >= 1){
      if(st.count(nxt) > 1) return true;
      // ignore if all three are the same: ex. aaa
      if(i < 2 || (i >= 2 && (s[i-2] != s[i-1] || s[i-1] != s[i]))) return true;
    }
    st.insert(nxt);
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
