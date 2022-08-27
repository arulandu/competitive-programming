/*
Contest: Educational Codeforces Round 134 (Div. 2)
Problem: [A] Image
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  string s, s2; cin >> s >> s2;
  string a = s + s2;
  set<char> st; for(auto x : a) st.insert(x);
  cout << st.size()-1 << "\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
