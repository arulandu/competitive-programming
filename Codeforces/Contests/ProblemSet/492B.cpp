#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n; ld l; cin >> n >> l;
    vector<ld> a (n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // sort ascending
    sort(a.begin(), a.end());

    // maximize half distance between lights and account for boundaries
    ld d = max(a[0], l-a[n-1]);
    for(int i = 1; i < n; i++){
        ld dif = a[i]-a[i-1];
        d = max(dif/2.L, d);
    }

    // precision
    cout.precision(numeric_limits<ld>::max_digits10);
    cout << d << '\n';

    return 0;
}