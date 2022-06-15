#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

ll solve(){
  ll a, b, c; cin >> a >> b >> c;
  ll n = abs(a-b)*2;
  if(n >= max(c, max(a, b))){
    return (((c+n/2)-1)%n)+1;
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cout << solve() << '\n';
  }

  return 0;
}
