#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;

bool solve(){
    ll n, k; cin >> n >> k;

    if(k % 2 != n % 2){
        return false;
    }

    if(n < k*k){
        return false;
    }

    return true;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
