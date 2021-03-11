#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void handle_io(bool end, string filename=""){
    if(end){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

    if(filename.length() > 0){
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

// O(N + 3N + N) => O(N)
int main(){
    handle_io(true, "hps");

    int n;
    cin >> n;
    int ar[n];

    // construct optimal responses to input
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        if(x == 'P'){
            ar[i] = 2;
        } else if(x == 'H'){
            ar[i] = 1;
        } else if(x == 'S'){
            ar[i] = 0;
        }
    }

    // prefix sums: H=0, P=1, S=2
    int pref[3][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            pref[j][i] = (i > 0 ? pref[j][i-1] : 0) + (ar[i] == j);
        }
    }

    // get maximum over a moving "split point" x
    int m = INT_MIN;
    for(int i = 0; i < n; i++){
        int l = max(max(pref[0][i], pref[1][i]), pref[2][i]);
        int r = max(max(pref[0][n-1]-pref[0][i],pref[1][n-1]-pref[1][i]), pref[2][n-1]-pref[2][i]);
        m = max(m, l+r);
    }
    cout << m << '\n';

    return 0;
}
/*
5
P
P
H
P
S
*/