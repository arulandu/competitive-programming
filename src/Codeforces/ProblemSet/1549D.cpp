#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<ll> dif(n-1);
  for(int i = 0; i < n-1; i++){
    dif[i] = a[i+1]-a[i];
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
