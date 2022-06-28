/*
Contest: Codeforces Round #803 (Div. 2)
Problem: [A] XOR Mixup
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n; cin >> n;
  vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
  // if xor of everything except element == element, done. (a^b)^b=a
  int xr = 0; for(auto x : v) xr ^= x;
  for(auto x : v){
    if((xr^x) == x) return x;
  }
  assert(false);
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << 'x' << '\n';

  return 0;
}
