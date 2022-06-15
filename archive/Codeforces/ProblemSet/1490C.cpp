#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;

bool solve(){
    ll x; cin >> x;
    for(ll a = 1; a < cbrtl(x); a++){
        ll b3 = x-powl(a, 3);
        ll cbrt = round(cbrtl(b3));
        if(cbrt*cbrt*cbrt == b3){
            return true;
        }
    }

    return false;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}
