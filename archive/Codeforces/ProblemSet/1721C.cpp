/*
Contest: Educational Codeforces Round 134 (Div. 2)
Problem: [C] Min-Max Array Transformation
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  // read
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  vector<ll> mn(n, 1e18), mx(n, -1e18);

  multiset<int> extra; for(auto x : b) extra.insert(x); // choices
  for(int i = n-1; i >= 0; i--){
    auto it = lower_bound(b.begin(), b.end(), a[i]); // get min >= 
    assert(it != b.end()); mn[i] = *it-a[i];

    mx[i] = *--extra.end()-a[i]; // save max choice
    auto eit = extra.lower_bound(a[i]); extra.erase(eit); // use min choice
  }

  for(auto x : mn) cout << x << " "; cout << '\n';
  for(auto x : mx) cout << x << " "; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
