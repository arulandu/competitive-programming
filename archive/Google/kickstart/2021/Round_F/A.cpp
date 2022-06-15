#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

void solve(){
  ll n; cin >> n;
  string s; cin >> s;
  ll f1 = -1, l1 = -1;
  for(ll i = 0; i < n; i++){
    if(s[i] == '1'){
      if(f1 == -1) f1 = i;
      l1 = i;
    }
  }

  ll c = f1*(f1+1)/2 + (n-l1-1)*(n-l1)/2;
  // cout << '\n';
  // cout << "f1: " << f1 << " l1: " << l1 << " start c: " << c << '\n';

  ll p = f1;
  for(ll i = f1+1; i <= l1; i++){
    if(s[i] == '1'){
      // cout << "p: " << p << " i: " << i << "c: " << c;
      c += ((i-p-1)*(i-p+1)+(i-p-1)%2)/4;
      // cout << " nc: " << c << '\n';
      p = i;
    }
  }
  
  cout << c;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
    cout << "\n";
  }

  return 0;
}
