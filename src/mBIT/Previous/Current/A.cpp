#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, q;
  cin >> n >> q;
  ll a[n];
  ll p[n+1];
  p[0] = 0;
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    p[i+1] = a[i]+p[i];
  }

  for(ll i = 0; i < q; i++){
    ll u, v;
    cin >> u >> v;
    if(u > v){
      ll t = v;
      v = u;
      u = t;
    }
    ll p1 = p[v-1]-p[u-1];
    ll p2 = p[n]-p1;
    cout << min(p1, p2) << '\n';
  }

  return 0;
}
