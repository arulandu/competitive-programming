#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

bool solve(){
    int n, x; cin >> n >> x;
    int oc = 0, ec = 0;
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        if(v % 2 == 0){
            ec++;
        } else {
            oc++;
        }
    }

    // reduce with even to least odd x if possible
    if(x % 2 != ec % 2){
        x -= min(ec, x-1);
    } else {
        x -= min(max(ec-1, 0), x-1);
    }

    return (x <= oc && x % 2 == 1);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        cout << (solve() ? "Yes" : "No") << '\n';
    }

    return 0;
}