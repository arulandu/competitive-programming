#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;
  ll c1 = n/3, c2 = n/3;
  if(n%3 == 2){
    c2++;
  } else if(n%3 == 1){
    c1++;
  }
  cout << c1 << ' ' << c2 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
