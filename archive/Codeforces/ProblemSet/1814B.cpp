/*
Contest: Educational Codeforces Round 146 
Problem: [B] Long Legs
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll cdiv(ll a, ll b){
  if(a%b == 0) return a/b;
  return (a/b) + 1;
}

// count moves with m stepsize
ll f(ll a, ll b, ll m) {
  return cdiv(a, m) + cdiv(b, m) + m-1;  
}

void solve(){
  ll a, b; cin >> a >> b;

  ll x = sqrt(a+b); // fuzzy search around this number
  pair<ll, ll> mn = {-1, a+b};
  ll th = 2; // fuzzy tolerance

  ll pv = f(a, b, x);
  for(int i = x; i <= a+b; i++){
    ll v = f(a, b, i);
    if(v > pv+th) break;
    if(v < mn.second) mn = {i, v};
    ll pv = v;
  }

  pv = f(a, b, x);
  for(int i = x; i >= 1; i--){
    ll v = f(a, b, i);
    if(v > pv+th) break;
    if(v < mn.second) mn = {i, v};
    ll pv = v;
  }

  cout << mn.second << '\n'; // print best
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
