/*
Contest: Codechef Starters 43
Problem: [C] Make them Equal
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool m2(ll &mod, ll &a, ll &b){
  ll x = (a-b)%mod; if(x < 0) x += mod;
  return x == (mod >> 1);
}

bool solve(){
  /*
  Observation: if odd, even, even: 2^0 goes to the odd.
  Generalization: 
  if two elements equal and the other is 2^i off in mod 2^(i+1), 2^i goes to the off
  */
  ll a, b, c; cin >> a >> b >> c;
  ll mod = 1ULL; ll op = 0;
  while(!(a == b && b == c) && op++ < 63){
    mod <<= 1;
    ll ma = a % mod, mb = b % mod, mc = c % mod;

    // check 3 permutations of a = b and c - a = 2^i mod 2^(i+1) and add if valid
    if(ma == mb && m2(mod, ma, mc)){
      c += (mod >> 1);
    } else if(mb == mc && m2(mod, mb, ma)){
      a += (mod >> 1);
    } else if(ma == mc && m2(mod, ma, mb)){
      b += (mod >> 1);
    } else {
      return false;
    }
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
