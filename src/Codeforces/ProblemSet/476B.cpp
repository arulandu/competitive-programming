#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

// ways to sum s with c spaces of +-1
int f(int s, int c){
    if(c == 0) return s == 0;
    return f(s-1, c-1) + f(s+1, c-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(16);

    string s1, s2; cin >> s1 >> s2;

    // calculate position differential and empty spaces
    int s = 0;
    for(auto x : s1){
        s += (x == '+' ? 1 : -1);
    }
    int c = 0;
    for(auto x : s2){
        if(x == '+'){
            s--;
        } else if(x == '-'){
            s++;
        } else {
            c++;
        }
    }

    cout << ((ld) f(s, c))/pow(2.L, c) << '\n';

    return 0;
}
