#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
    int n; cin >> n;
    string x; cin >> x;

    string a, b;
    bool mina = false;
    for(int i = 0; i < x.size(); i++){
        if(i == 0){
            if(x[i] == '0'){
                a += '2'; b += '1';
                mina = true;
            } else if(x[i] == '1'){
                a += '2'; b += '2';
            } else if(x[i] == '2'){
                a += '1'; b += '1';
            }
        } else {
            if(x[i] == '0'){
                a += '0'; b += '0';
            } else if(x[i] == '1'){
                if(mina){
                    a += '0'; b += '1';
                } else {
                    a += '1'; b += '0';
                    mina = true;
                }
            } else if(x[i] == '2'){
                if(mina){
                    a += '0'; b += '2';
                } else {
                    a += '1'; b += '1';
                }
            }
        }
    }

    cout << a << '\n' << b << '\n';
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