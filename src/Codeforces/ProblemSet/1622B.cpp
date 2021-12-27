/*
Contest: Educational Codeforces Round 120 
Problem: [B] Berland Music
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
  string r; cin >> r;
  set<int> lw, hi;
  for(int i = 0; i < n; i++){
    if(r[i] == '1'){
      hi.insert(v[i]);
    } else {
      lw.insert(v[i]);
    }
  }

  map<int, int> m;
  int c = 0, q = 1;
  for(auto x : lw){
    m[x] = q;
    c += abs(m[x]-q); q++;
  }
  for(auto x : hi){
    m[x] = q;
    c += abs(m[x]-q); q++;
  }

  for(auto x : v){
    cout << m[x] << ' ';
  }
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
