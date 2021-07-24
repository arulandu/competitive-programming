#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  string s; cin >> s;
  map<char, int> m;
  for(auto c : s){
    if(m.count(c) == 0){
      m[c] = 0;
    }
    m[c]++;
  }

  int c = 0;
  for(auto p : m){
    if(p.second > 1){
      c += 2;
    } else if(p.second > 0){
      c++;
    }
  }
  cout << c/2 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
