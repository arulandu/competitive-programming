#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MOD = 1e9+7;

ll fz(ll n){
  ll Z = 1; // 0
  for(ll i = 1; i < n; i *= 10){
    Z += n-i; Z %= MOD;
  }

  return Z;
}


// Z = len(x) for x in range(n)
//   = ceil(log(x)) for x in range(n)
//   = 

void solve(){
  ll a, l, r, n; cin >> a >> l >> r >> n;
  ll Z = fz(n)%MOD;
  // ll ans = (n*n)*(a + 5 + n*(l + r + 10) + 2*Z) + (n+1)*(2*n*Z);
  ll ans = (((n*n)%MOD)*((a + 5 + n*((l + r + 10)%MOD) + 2*Z)%MOD)%MOD) + (((n+1)*((2*n*Z)%MOD))%MOD);
  ans %= MOD;
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}

/*
c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + ... + a[i][n-1]*b[n-1][j];

let Z = sum(len(x) for x in range(n))

line i, j length =
(a + 4 + len(i) + len(j)) + 1 + (n-1) + n*(l+r+9+len(i)+len(j)) + 2*Z + 1
=
a + 5 + n*(l + r + 10) + 2*Z + (n+1)*(len(i) + len(j))

ANS = 
sum across i, j of 
a + 5 + n*(l + r + 10) + 2*Z + (n+1)*(len(i) + len(j))
= 
(n**2)*(a + 5 + n*(l + r + 10) + 2*Z) + (n+1)(len(i)+len(j) across i, j)
=
(n**2)*(a + 5 + n*(l + r + 10) + 2*Z) + (n+1)(2*n*Z)

full length:

ret[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];

ret[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];

ret[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];

ret[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];


*/