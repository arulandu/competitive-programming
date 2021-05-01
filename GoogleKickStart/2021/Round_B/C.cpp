#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

bool isp(ll& x){
    if(x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;

    for(ll a = 11; a < sqrt(x); a++){
        if(x % a == 0) return false;
    }

    return true;
}

ll maxp(ll n){
    n = n % 2 == 0 ? n-1 : n;
    for(ll x = n; x >= 2; x -= 2){
        if(isp(x)) return x;
    }

    return -1;
}

ll minp(ll n){
    n = n % 2 == 0 ? n+1 : n;
    for(ll x = n; true; x += 2){
        if(isp(x)) return x;
    }

    return -1;
}

void solve(){
    ll z;
    cin >> z;

    ll p1 = maxp(sqrt(z));
    
    ll prod = p1*minp(p1 + 1);
    if(prod > z) prod = p1*maxp(p1-1);

    cout << prod;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
