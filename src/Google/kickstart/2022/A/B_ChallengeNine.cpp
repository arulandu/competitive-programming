/*
Contest: Google Kickstart Round A 2022
Problem: [B] Challenge Nine
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  string s; cin >> s;
  vector<int> v(s.size());

  // find target number
  ll sm = 0;
  for(int i = 0; i < s.size(); i++){
    v[i] = (int)(s[i]-'0');
    sm += v[i];
  }
  int r = (9-(sm % 9)) % 9;

  // add before first digit greater
  bool g = false;
  for(int i = 0; i < v.size(); i++){
    if(!g && r < v[i] && (r != 0 || i > 0)){
      cout << r;
      g = true;
    }
    cout << v[i];    
  }
  
  if(!g) cout << r; // or at the end
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
