/*
Contest: Educational Codeforces Round 121
Problem: [A] Equidistant letters
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  string s; cin >> s;
  string o = s; for(int i = 0; i < s.size(); i++) o[i] = '.';
  map<char, int> m;
  for(auto x : s) {
    if(!m.count(x)) m[x] = 0;
    m[x]++;
  }

  // move pairs adjacent to front and add rest
  int j = 0;
  for(auto p : m){
    if(p.second == 2){
      o[j] = p.first; o[j+1] = p.first;
      j+=2;
    } else {
      o[j] = p.first;
      j++;
    }
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
