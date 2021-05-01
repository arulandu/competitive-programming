#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
    int n;
    string s;
    cin >> n >> s;

    int ar[n];
    ar[0] = 1;
    cout << 1;

    for(int i = 1; i < n; i++){
        cout << " ";
        ar[i] = s.at(i) > s.at(i-1) ? ar[i-1] + 1 : 1;
        cout << ar[i];
    }
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
