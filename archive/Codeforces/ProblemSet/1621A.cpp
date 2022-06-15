/*
Contest: Codeforces Hello 2022
Problem: [A] Stable Arrangement of Rooks
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;
  if(k > (n+1)/2) { 
    cout << -1 << '\n'; return;
  }
  int c = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i % 2 == 0 && i == j && c < k){
        cout << "R";
        c++;
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
