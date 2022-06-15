/*
Contest: Codeforces Round #767 (Div. 2)
Problem: [D] Peculiar Movie Preferences
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n;
  vector<string> ss(n); for(int i = 0; i < n; i++) cin >> ss[i];

  // single is palindrome
  for(auto s : ss){
    if(s.size() == 1 || (s.size() == 2 && s[0] == s[1]) || (s.size() == 3 && s[0] == s[2])){
      return true;
    }
  }

  // otherwise pair is palindrom
  multiset<string> ck; // hold previous strings
  for(auto s : ss){
    // ba pairs with ab or abc
    if(s.size() == 2){
      string rev = ""; rev += s[1]; rev += s[0];
      auto it = ck.lower_bound(rev);
      if(it != ck.end()){
        if((*it)[0] == s[1] && (*it)[1] == s[0]) return true;
      }
    } else {
      // cba pairs with ab or abc
      string rev = ""; rev += s[2]; rev += s[1];
      if(ck.count(rev) > 0 || ck.count(rev + s[0]) > 0) return true;
    }
    ck.insert(s);
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}
