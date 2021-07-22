#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
typedef long double ld;

// O(n^2)
int solve(){
    int n; cin >> n;
    map<int, int> mc; // number, count
    vector<int> nums; // distinct

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(mc.count(x) > 0){
            mc[x]++;
        } else {
            mc[x] = 1;
            nums.push_back(x);
        }
    }

    map<int, int> ms; // s to count
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            int s = nums[i]+nums[j];

            if(i == j && mc[nums[i]] < 2) continue;
            if(ms.count(s) == 0){
                ms[s] = 0;
            }

            ms[s] += i == j ? mc[nums[i]]/2 : min(mc[nums[i]], mc[nums[j]]);
        }
    }    

    pair<int, int> mxp; // pair with max count
    for(auto p : ms){
        if(p.second > mxp.second){
            mxp = p;
        }
    }

    return mxp.second;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        cout << solve() << '\n';
    }

    return 0;
}