#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    // read input    
    vector<pair<int, int>> v (n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    // sort increasing by first term
    sort(v.begin(), v.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.first < p2.first;
    });

    int prev_mx = -1; // max second term of previous terms with unlike first term
    int cur_mx = -1; // max second term of previous terms with like first term

    bool res = false; // exists or not
    for(int i = 0; i < n; i++){
        // move current max to previous if first term changed
        if(i > 0 && v[i].first != v[i-1].first){
            prev_mx = max(cur_mx, prev_mx);
            cur_mx = -1;
        }

        // check existence
        if(v[i].second < prev_mx){
            res = true;
            goto skip;
        }

        // update max
        cur_mx = max(cur_mx, v[i].second);
    }

    // log
    skip:;
    cout << (res ? "Happy Alex" : "Poor Alex") << '\n';

    return 0;
}
