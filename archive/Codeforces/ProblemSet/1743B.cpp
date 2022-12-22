/*
Contest: Educational Codeforces Round 137 (Rated for Div. 2)
Problem: [B] Permutation Value
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  // alternate read 1, n, 2, n-1 ... gives value 2
  for(int i = 0; i < n; i++){
    if(i%2 == 0){
      cout << (1+(i/2)) << ' ';
    } else {
      cout << (n-(i/2)) << ' ';
    }
  }
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
