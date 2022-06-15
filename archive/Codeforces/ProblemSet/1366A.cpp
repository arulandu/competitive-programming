#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;

void solve(){
    int a, b; cin >> a >> b;
    cout << min(min((a+b)/3, a), b) << '\n';
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

// https://codeforces.com/problemset/problem/1366/A

/*
x=shovels, y=swords

Sticks: 2x+y <= a
Diamonds: x+2y <= b
x, y >= 0

z = x+y
max(x+y) = max(z)

*/

