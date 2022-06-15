/*
Contest: Codeforces Good Bye 2021: 2022 is NEAR
Problem: [A] Integer Diversity
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  map<int, int> m;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(m.count(abs(a)) < 1) m[abs(a)] = 0;
    m[abs(a)]++;
  }

  int c = 0;
  for(auto p : m) {
    c += p.first == 0 ? min(1, p.second) : min(2, p.second);
  }
  cout << c << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
