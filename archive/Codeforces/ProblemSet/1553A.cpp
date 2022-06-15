#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
    ll n; cin >> n;
    cout << n/10 + (n % 10 == 9 ? 1 : 0) << '\n';
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