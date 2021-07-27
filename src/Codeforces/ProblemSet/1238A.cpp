#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n, r; cin >> n >> r;
  vector<int> v(n);

  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  // sort ascending
  sort(v.begin(), v.end());

  // iterate right to left
  int c = 0;
  int p = 0;
  int pv = -1;
  for(int i = n-1; i >= 0; i--){
    if(pv == v[i]) continue;
    pv = v[i];
  
    if(v[i]-p <= 0) continue; // traps

    // kill
    c++;
    p += r;
  }

  cout << c << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  while(q--){
    solve();
  }

  return 0;
}
