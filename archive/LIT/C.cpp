#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll solve(){
  ll inf = 1e18;

  int n; ll k; cin >> n >> k;
  vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  if(k%2 == 1) k--;
  int mdr0 = (n-1)/2;
  int l = 0; int mdr = mdr0; ll m = a[mdr0];
  while(k > 0){
    while(mdr < n-1 && a[mdr+1] == m) mdr++;
    ll dk = mdr-mdr0+1; // # to bump
    ll r = min(k/(2*dk), mdr == n-1 ? inf : a[mdr+1]-m); // # of bumps
    if(r == 0) return m; // empty
    dk *= r; k -= 2*dk; // buy ops

    // cout << mdr << ' ' << r << ' ' << k << "\n";
    
    // # check sum balance
    while(dk > 0 && l >= mdr0){
      if(a[l] == 0){
        l++;
        if(l >= mdr0) return m;
      }
      ll d = min(dk, a[l]);
      dk -= d; a[l] -= d;
    }

    // cout << "upd: " << l << ' ' << a[l] << '\n';
    // update
    m += r;
  }

  return m;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
