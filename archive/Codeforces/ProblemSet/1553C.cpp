#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
    string s; cin >> s;

    int p1 = 0, p2 = 0;
    int m1 = 10, m2 = 10;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            if(i % 2 == 0){
                p1++;
            } else {
                p2++;
            }
        } else if(s[i] == '?'){
            if(i % 2 == 0){
                p1++;
            }
        }

        // cout << i+1 << ' ' << p1 << ' ' << p2 << ' ' << '\n';

        if(p1-p2 > (10-i)/2 || p2-p1 > (9-i)/2){
            m1 = i+1;
            break;
        }
    }

    // cout << "d\n";
    p1 = 0; p2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            if(i % 2 == 0){
                p1++;
            } else {
                p2++;
            }
        } else if(s[i] == '?'){
            if(i % 2 == 1){
                p2++;
            }
        }

        // cout << i+1 << ' ' << p1 << ' ' << p2 << ' ' << '\n';

        if(p1-p2 > (10-i)/2 || p2-p1 > (9-i)/2){
            m2 = i+1;
            break;
        }
    }

    cout << min(m1, m2) << '\n';
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