/*
Contest: CodeChef Starters 70 Div. 3
Problem: Cost of Groceries
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, x; cin >> n >> x;
  vector<int> as(n), bs(n);
  for(int i = 0; i < n; i++) cin >> as[i];
  for(int i = 0; i < n; i++) cin >> bs[i];
  // sum
  int s = 0;
  for(int i = 0; i < n; i++){
    if(as[i] >= x) s += bs[i];
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
