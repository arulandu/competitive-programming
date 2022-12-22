/*
Contest: Educational Codeforces Round 137 (Rated for Div. 2)
Problem: [C] Save the Magazines
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> as(n); for(int i = 0; i < n; i++) cin >> as[i];

  int mn = -1; int ans = 0;
  for(int i = 0; i <= n; i++){
    if(i < n && s[i] == '1'){
      mn = min(mn, as[i]);
      ans += as[i]; // add by default
    } else {
      if(mn >= 0) ans -= mn; // shift 1 block to remove min
      if(i < n) {
        mn = as[i]; // reset
        ans += as[i]; // add by default
      }
    }
  }

  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
