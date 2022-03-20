#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n, m; cin >> n >> m;
  int s = 0; for(int i = 0; i < n; i++){ int x; cin >> x; s += x; }
  return s%m;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": " << solve() << '\n';
  }

  return 0;
}
