#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vector<ll> pv(n); for(int i = 0; i < n; i++) cin >> pv[i]; sort(pv.begin(), pv.end());
  ll m = pv[n/2]; ll r = 0; for(auto p : pv) r += abs(m-p);
  cout << r << '\n';

  return 0;
}
