/*
Contest: Educational Codeforces Round 17
Problem: [B] USB vs. PS/2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  // ios_base::sync_with_stdio(0); cin.tie(0);

  int a, b, c, m; cin >> a >> b >> c >> m;

  multiset<ll> m1, m2;
  for(int i = 0; i < m; i++){
    ll v; cin >> v; string s; cin >> s;
    if(s == "USB") {
      m1.insert(v);
    } else {
      m2.insert(v);
    }
  }

  multiset<ll> mf, rem;
  auto it = m1.begin();
  for(int i = 0; it != m1.end(); i++){
    if(i < a){ 
      mf.insert(*it);
    } else {
      rem.insert(*it);
    }
    it++;
  }

  it = m2.begin();
  for(int i = 0; it != m2.end(); i++){
    if(i < b){
      mf.insert(*it);
    } else {
      rem.insert(*it);
    }
    it++;
  }

  it = rem.begin();
  for(int i = 0; i < c && it != rem.end(); i++){
    mf.insert(*it);
    it++;
  }

  ll res = 0;
  for(auto f : mf) res += f;
  
  cout << mf.size() << ' ' << res << '\n';

  return 0;
}
