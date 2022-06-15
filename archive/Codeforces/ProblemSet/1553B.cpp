#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

bool solve(){
    string s; cin >> s;
    string t; cin >> t;

    for(int i = 0; i < t.size(); i++){
        // invalid forward
        if(i+1 > s.size() || s.find(t.substr(0, i+1)) == string::npos){
            return false;
        }

        // break target into forward and reverse
        string f = t.substr(0, i+1);
        string e = t.substr(i+1, t.size()-i-1);
        reverse(e.begin(), e.end());

        // all occurrences of forward
        vector<int> pos;
        int p = s.find(f, 0);
        while(p != string::npos){
            pos.push_back(p);
            p = s.find(f, p+1);
        }
        
        // check
        for(auto x : pos){
            int ci = x+(int)f.size()-2-(int)e.size()+1;
            if(ci >= 0 && s.substr(x+(int)f.size()-2-(int)e.size()+1, e.size()).compare(e) == 0){
                return true;
            }
        }
    }

    return false;
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