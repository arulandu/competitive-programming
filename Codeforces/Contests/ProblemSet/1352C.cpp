#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

ll solve(){
    ll n, k; cin >> n >> k;
    ll l = 1, r = 2e9;
    while(l <= r){
        ll m = (l+r)/2;
        ll v = m-m/n;

        if(v < k){
            l = m+1;
        } else if (v > k){
            r = m-1;
        } else if (v == k){
            return m % n == 0 ? m-1 : m;
        }
    }

    return -1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
    return 0;
}