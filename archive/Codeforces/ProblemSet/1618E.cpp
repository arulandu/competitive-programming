/*
Contest: Codeforces Round #760 (Div. 3)
Problem: [E] Singers' Tour
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;

  vector<ll> b(n); for(int i = 0; i < n; i++) cin >> b[i];
  ll bs = 0; for(auto bi : b) bs += bi;
  
  // compute sum of a[i] = S
  ll as = 2*bs; 
  if(as % (n*(n+1)) != 0) {
    cout << "NO" << '\n'; return;
  }
  as /= n*(n+1);

  // a[i] = S - b[i] + b[i-1]
  vector<ll> a(n, -1);
  for(int i = 1; i < n; i++){
    a[i] = as-b[i]+b[i-1];
    if(a[i] % n != 0){
      cout << "NO" << '\n'; return;
    }
    a[i] /= n;
  }

  // a[0] = S - (sum of a[i] for i = [1,n))
  ll as1n = 0; for(int i = 1; i < n; i++) as1n += a[i];
  a[0] = as-as1n;

  // check if invalid (< 1)
  for(int i = 0; i < n; i++){
    if(a[i] < 1) {
      cout << "NO" << '\n'; return;
    }
  }

  cout << "YES" << '\n';
  for(auto ai : a) cout << ai << ' '; cout << '\n'; 
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
