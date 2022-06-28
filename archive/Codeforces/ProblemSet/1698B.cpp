/*
Contest: Codeforces Round #803 (Div. 2)
Problem: [B] Rising Sand
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n, k; cin >> n >> k;
  vector<ll> a(n); for(int i= 0; i < n; i++) cin >> a[i];
  if(k == 1) return (n-1)/2; // hard max

  // k>=2 rising never helps count so just check
  int c = 0;
  for(int i = 1; i < n-1; i++){
    if(a[i] > a[i-1]+a[i+1]) c++;
  }
  return c;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
