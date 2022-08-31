/*
Contest: Codechef Starters 54 (Div. 3)
Problem: [B] Equal Distinct
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n;
  vector<int> v(n, 0);
  for(int i = 0; i < n; i++){
    int k; cin >> k;
    for(int j = 0; j < k; j++){
      int x; cin >> x; x--;
      v[i] |= (1LL << x);
    }
  }

  // for(auto x : v) cout << bitset<5>(x) << ' '; cout << '\n';

  int t = (1LL<<5)-1;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if((v[i]|v[j]) == t) return true;
    }
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
