#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

bool solve(){
    string s, t; cin >> s >> t;

    // iterate from back
    int j = s.size() - 1, i = t.size() - 1;
    while(i >= 0){
        // backspace if not matching
        while(j >= 0 && s[j] != t[i]){
            j -= 2;
        }

        if(j < 0){
            return false;
        }
        i--;
        j--;
    }

    return true;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        cout << (solve() ? "YES" : "NO") << '\n';
    }

    return 0;
}