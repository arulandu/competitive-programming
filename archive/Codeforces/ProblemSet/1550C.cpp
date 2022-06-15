#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

bool invalid(int a, int b, int c){
    return (c >= b && b >= a) || (a >= b && b >= c);
}

void solve(){
  int n; cin >> n;
  /*
  If a_i, a_i+1, a_i+2 is non-increasing or non-decreasing, the subarray is bad.
  Any subarray of 5+ elements is bad. Any subarray of 1 or 2 length is good.
  If there is a non-increasing subseq. there is a non-decreasing one
  */
  vector<ll> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  ll c = n + n - 1; // length 1 or 2

  // length 3
  for(int i = 0; i < n - 2; i++){
    if(!invalid(a[i], a[i+1], a[i+2])) c++;
  }

  // length 4
  for(int i = 0; i < n-3; i++){
    if(!invalid(a[i], a[i+1], a[i+2]) &&
       !invalid(a[i], a[i+1], a[i+3]) &&
       !invalid(a[i], a[i+2], a[i+3]) &&
       !invalid(a[i+1], a[i+2], a[i+3])) {
      c++;
    }
  }

  cout << c << '\n';
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