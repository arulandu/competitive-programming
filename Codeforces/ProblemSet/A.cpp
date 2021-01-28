/*
NAME: Strange List
URL: https://codeforces.com/problemset/problem/1471/B
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    ll x;
    cin >> n >> x;
    cout << "x: " << x << '\n';

    vector<int> ar (n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cout << "i: " << i << '\n';
        cin >> ar[i];

        int t = 0;
        while(ar[i] % x == 0){
            cout << "t: " << t << " v: " << ar[i] << '\n';
            sum += pow(x, t) * ar[i];
            ar[i] /= x;
            t++;
        }
        sum += pow(x, t) * ar[i];
    }

    cout << sum << '\n';
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/*
2
1 2
12
4 2
4 6 8 2

4 -> [4, 2, 2, 1, 1, 1, 1]
6 -> [6, 3, 3]
8 -> [8, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1]
2 -> [2, 1, 1]
*/
