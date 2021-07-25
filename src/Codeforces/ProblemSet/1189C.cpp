#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    // prefix sum
    int p[n]; p[0] = v[0];
    for(int i = 1; i < n; i++){
        p[i] = p[i-1]+v[i];
    }

    // return max multiples of 10 in sum btwn bounds
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        int ans = p[r-1] - (l > 1 ? p[l-2] : 0);
        cout << ans / 10 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
