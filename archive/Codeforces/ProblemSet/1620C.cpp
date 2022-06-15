/*
Contest: Educational Codeforces Round 119
Problem: [C] BA-String
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n, k; ll x; cin >> n >> k >> x;
  string s; cin >> s;

  // compress stars
  vector<ll> sts;
  ll c = 0;
  for(ll i = 0; i < s.size(); i++){
    if(s[i] == '*') {
      c++;
    } else if(c > 0){
      sts.push_back(c);
      c = 0;
    }
  }
  if(c > 0) sts.push_back(c);

  vector<ll> cts(sts.size(), 0);

  // convert to c[i]*k+1 basis
  ll mod = 1;
  for(int i = sts.size()-1; i >= 0; i--){
    // !! important: stop multiplication if > x and check for overflow 
    ll nmod = mod > x ? mod : (mod > LONG_LONG_MAX/(sts[i]*k+1) ? LONG_LONG_MAX : mod*(sts[i]*k+1));
    cts[i] = ((x-1)%nmod)/mod;
    mod = nmod;
  }

  // write counts to string
  string sp; ll q = 0;
  for(ll i = 0; i < s.size();){
    if(s[i] == '*'){
      for(ll j = 0; j < cts[q]; j++) sp += 'b'; q++;
      while(i < s.size() && s[i] == '*') i++;
    } else {
      sp += s[i];
      i++;
    }
  }

  cout << sp << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
