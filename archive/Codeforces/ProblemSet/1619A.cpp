/*
Contest: Codeforces Round #762 (Div. 3)
Problem: [A] Square String?
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  string s; cin >> s;
  if(s.size() % 2) return false;
  return s.substr(0, s.size()/2) == s.substr(s.size()/2);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
