#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  string s (n/2, 'a');
  cout << (n==1 ? "a" : s+(n%2==1?"bc":"b")+s.substr(0, s.size()-1)) << '\n';
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
