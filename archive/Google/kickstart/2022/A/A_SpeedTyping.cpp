/*
Contest: Google Kickstart Round A 2022
Problem: [A] Speed Typing
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  string si, sp; cin >> si >> sp;

  // two pointers
  int i = 0, j = 0, c = 0;
  while(i < si.size() && j < sp.size()){
    while(j < sp.size() && sp[j] != si[i]) {
      j++;
      c++;
    }
    if(j >= sp.size()) return -1;
    i++; j++;
  }
  if(i < si.size()) return -1;
  return c+sp.size()-j;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    int v = solve();
    if(v == -1) {
      cout << "IMPOSSIBLE";
    } else {
      cout << v;
    }
    cout << '\n';
  }

  return 0;
}
