#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve(){
    string str; cin >> str;
    stack<int> st;
    for(auto c : str){
        if(c == 'B' && st.size()){
            st.pop();
        } else {
            st.push(c);
        }
    }

    cout << st.size() << '\n';
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
