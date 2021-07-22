#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

int main(){
  handle_io(true);

  int n, q;
  cin >> n >> q;
  ll h[n];
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }

  sort(h, h+n);

  for(int i = 0; i < q; i++){
    ll x, k;
    cin >> x >> k;
    cout << upper_bound(h, h+n, x+k) - lower_bound(h, h+n, x-k) << '\n';
  }

  return 0;
}
