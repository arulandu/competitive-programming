#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int p, g, c, y; cin >> p >> g >> c >> y;
  cout << (2200*ceil(p/19.)+1830*ceil(g/24.)+2160*ceil(c/18.)+2640*ceil(y/16.)) << '\n';

  return 0;
}
