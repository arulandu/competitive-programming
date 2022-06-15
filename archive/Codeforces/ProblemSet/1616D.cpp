/*
Contest: Good Bye 2021: 2022 is NEAR
Problem: [D] Keep the Average High
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> as(n); for(int i = 0; i < n; i++) cin >> as[i];
  int x; cin >> x;
  for(auto& a : as) a -= x;

  int s = n, sm = 0, mn = 2e9; // s = # selected, sm = sum of current segment, mn = min sub array sum in current segment
  for(int i = 0; i < n; i++){
    if(as[i] + mn < 0){
      s--; sm = 0; mn = 2e9;
    } else {
      sm += as[i]; mn = mn < 0 ? mn + as[i] : as[i];
    }
  }

  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
