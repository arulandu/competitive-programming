/*
Contest: Codeforces Global Round18
Problem: [B] And It's Non-Zero
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

// in a range [1, n - 1]
ll cnt(ll n, int k)
{
  if(k == 0) return (n-1)/2+(ll)((n-1)%2 == 1);
  ll res = (n >> (k + 1)) << k;

  if((n >> k) & 1) res += n & ((1ll << k) - 1);

  return res;
}

int solve(){
  ll l, r; cin >> l >> r;

  ll bl = log2(l), br = log2(r);

  if(bl == br) return 0;

  ll mx = LONG_LONG_MIN;
  for(int k = 0; k <= br; k++){
    ll x = cnt(r+1, k)-cnt(l, k);
    // cout << r-l+1-x << ' ';
    mx = max(mx, x);
  }
  // cout << '\n';

  return r-l+1-mx;

  // int b = log2(r) + 1;
  // int bt[b]; for(int i = 0; i < b; i++) bt[i] = 0;
  // for(int i = l; i <= r; i++){
  //   // cout << "i: " << i << " | ";
  //   for(int j = 0; j < b; j++){
  //     int x = (i&(1<<j)) == 0;
  //     // cout << !x << ' ';
  //     bt[j] += x;
  //   }
  //   // cout << '\n';
  // }

  // int mn = INT_MAX;
  // for(int j =0; j < b; j++){
  //   cout << bt[j] << ' ';
  //   mn = min(mn, bt[j]);
  // }
  // cout << '\n';
  // return mn;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
