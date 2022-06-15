#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

const ll MAXN = 1e9;
const int MAXP2 = 63;
string p2[MAXP2];

int calc(string &t, string &n){
  int c = 0;
  int ti = 0, ni = 0;
  for(; ni < n.size() && ti < t.size(); ni++){
    if(n[ni] == t[ti]){
      ti++;
    } else {
      c++;
    }
  }
  if(ti < t.size()){
    c += t.size()-ti;
  }
  if(ni < n.size()){
    c += n.size()-ni;
  }

  // cout << t << ' ' << c << ' ' << ti << ' ' << ni << '\n'; 

  return c;
}

int solve(){
  string n; cin >> n;
  int m = n.size()+1;
  for(int i = 0; i < MAXP2; i++){
    m = min(m, calc(p2[i], n));
  }
  return m;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll x = 1;
  for(int i = 0; i < MAXP2; i++){
    p2[i] = to_string(x);
    x *= 2;
  }

  int t; cin >> t;
  while(t--){
    cout << solve() << '\n';
  }

  return 0;
}
