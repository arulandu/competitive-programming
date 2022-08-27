/*
Contest: Codeforces Round #816 (Div.2)
Problem: [C] Monoblock
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n, m; cin >> n >> m;
  vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i];

  // find breaks: i | a[i] and a[i+1] are different
  set<ll> bks;
  for(int i = 0; i < n-1; i++){
    if(a[i] != a[i+1]) bks.insert(i);
  }

  ll s = n*(n+1)/2; // add 1 for all segments

  // number of segments including break at i
  auto subs = [&n](ll i){
    return n*(n+1)/2 - (n-(i+1))*(n-(i+1)+1)/2 - (i+1)*(i+2)/2;
  };

  // remove break
  auto remove = [&subs, &s, &bks](ll ind){
    bks.erase(ind); s -= subs(ind);
  };

  // add break
  auto add = [&subs, &s, &bks](ll ind){
    bks.insert(ind); s += subs(ind);
  };

  // add # of segments for all breaks
  for(auto bk : bks) s += subs(bk);

  // update breaks every query and recalculate accordingly
  for(int i = 0; i < m; i++){
    ll ind, x; cin >> ind >> x; ind--;
    a[ind] = x;
    if(ind > 0 && bks.count(ind-1) == 1 && a[ind-1] == a[ind]) remove(ind-1);

    if(ind < n-1 && bks.count(ind) == 1 && a[ind] == a[ind+1]) remove(ind);

    if(ind < n-1 && bks.count(ind) == 0 && a[ind] != a[ind+1]) add(ind);

    if(ind > 0 && bks.count(ind-1) == 0 && a[ind-1] != a[ind]) add(ind-1);

    cout << s << '\n'; // answer
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  while(t--) solve();

  return 0;
}
