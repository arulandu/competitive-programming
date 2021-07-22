#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

// O(nlogn)
void solve(){
    // read input and sort ascending
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> ar(n);
    for(ll i = 0;i < n; i++){
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());

    ll c = 0;

    // iterate through a_i and use binary search twice to find bounds on a_j
    for(ll i = 0; i < n; i++){
        auto lb = lower_bound(ar.begin()+i+1, ar.end(), l-ar[i]);
        auto ub = upper_bound(ar.begin()+i+1, ar.end(), r-ar[i]);

        // dont decrement if no item is found
        if(ub - ar.begin() != 0){
            ub--;
        }

        c += ub-lb+1;
    }

    cout << c << '\n';
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