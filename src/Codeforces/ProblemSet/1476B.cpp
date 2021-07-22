#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;

void solve(){
    // read input
    ll n; ld k; cin >> n >> k;
    vector<ll> p (n);
    for(ll i = 0; i < n; i++){
        cin >> p[i];
    }

    // change the first term only
    ld s = p[0];
    ld da = 0;
    for(ll i = 1; i < n; i++){
        ld minda = (100.L/k)*p[i]-s;
        da = max(max(minda, 0.L), da);
        s += p[i];
    }

    // avoid precision errors in during ceill
    if(abs(llroundl(da)-da) < EPS){
        cout << llroundl(da) << '\n';
    } else {
        cout << (ll) ceill(da) << '\n';
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}