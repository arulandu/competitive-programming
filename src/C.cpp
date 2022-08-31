/*
Contest: Codechef Starters 54 (Div. 3)
Problem: [C] Team of Two
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n;
  map<int, int> m;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    if(m.count(x) == 0) m[x] = 0;
    m[x]++;
  }
  
  // split distinct
  if(m.size() % 2 == 0) return true;
  for(auto p : m){
    if(p.second > 1) return true; // add one
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
