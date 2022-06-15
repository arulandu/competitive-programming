/*
Contest: Codeforces Round #767 (Div. 2)
Problem: [A] Download More RAM
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;
  vector<pair<int, int>> rms(n);
  for(int i = 0; i < n; i++) cin >> rms[i].first;
  for(int i = 0; i < n; i++) cin >> rms[i].second;

  // choose items that require least first
  sort(rms.begin(), rms.end());
  for(int i = 0; i < n; i++){
    if(rms[i].first > k) break;
    k += rms[i].second;
  }

  cout << k << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
