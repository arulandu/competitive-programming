#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  int s = 0;
  for(int i = 0; i < n; i++){
    char c; cin >> c; c-='0';
    s += c;
    if(c != 0 && i < n-1) s++;
  }
  cout << s << '\n';
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
