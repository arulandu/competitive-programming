#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll dp[n][2]; // (ind, sign to place) = strength
    memset(dp, 0, sizeof(dp)); dp[0][0] = a[0]; dp[0][1] = 0; // first to place is always +

    for(int i = 0; i < n-1; i++){
        dp[i+1][0] = max(dp[i][0], dp[i][1]+a[i+1]);
        dp[i+1][1] = max(dp[i][1], dp[i][0]-a[i+1]);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
