/*
Contest: Codechef January Lunchtime 2022 Div. 2
Problem: [A] Subarray permutations
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;
  if(k == 1){
    if(n == 1){
      cout << 1 << '\n'; return;
    } else {
      cout << -1 << '\n'; return;
    }
  }
  
  vector<int> v(n); // ascending consecutive till k-1 then descending consecutive
  for(int i = 0; i < k-1; i++){
    v[i] = i+1;
  }

  for(int i = k-1; i < n; i++){
    v[i] = n-i+k-1;
  }

  for(auto x : v) cout << x << " "; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
