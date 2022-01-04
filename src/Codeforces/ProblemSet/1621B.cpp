/*
Contest: Codeforces Hello 2022
Problem: [B] Integers Shop
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct Seg {
  ll l, r, c;
};

void solve(){
  int n; cin >> n;
  vector<Seg> sgs(n); for(int i = 0; i < n; i++) cin >> sgs[i].l >> sgs[i].r >> sgs[i].c;
  
  int lm = 0, rm = 0; ll mn = LONG_LONG_MAX;
  for(int i = 0; i < n; i++){
    if(sgs[i].l < sgs[lm].l || sgs[i].r > sgs[rm].r) mn = LONG_LONG_MAX;
    if((sgs[i].l == sgs[lm].l && sgs[i].c < sgs[lm].c) || sgs[i].l < sgs[lm].l) lm = i;
    if((sgs[i].r == sgs[rm].r && sgs[i].c < sgs[rm].c) || sgs[i].r  > sgs[rm].r) rm = i;
    mn = min(mn, sgs[lm].c + sgs[rm].c);
    if(sgs[i].l == sgs[lm].l && sgs[i].r == sgs[rm].r) mn = min(mn, sgs[i].c);
    cout << mn << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
