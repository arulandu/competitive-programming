#include <bits/stdc++.h>

using namespace std;
#define ll long long

void passcode(vector<ll> &a, ll k){
  ll n = a.size();
  ll s = 0;
  for(ll i = 0; i < n; i++){
    s += (n-1-i)*a[i] + (2*i-n+1)*(a[i]%k);
  }

  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t = 1;
  cin >> t;
  while(t--) {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); 
    for(ll i = 0; i < n; i++) cin >> a[i];

    passcode(a, k);
  }

  return 0;
}
