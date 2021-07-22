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

int n, k;

bool check(vector<ll> &v, ll r){
    // greedily place haybale at x_i+r
    int p = v[0]+r, c = 1;
    for(int i = 1; i < v.size(); i++){
        if(v[i] <= p+r) {
            continue;
        }
        p = v[i]+r;
        c++;
    }

    // use count to check
    return c <= k;
}

int main(){
    handle_io(true, "angry");

    cin >> n >> k;

    // sort ascending
    vector<ll> v (n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    // binary search on min R
    ll l = 0, r = 1+(v[v.size()-1]-v[0])/2;
    while(l <= r){
        ll m = (l+r)/2;
        bool b = check(v, m);
        if(b){
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << l << '\n';

    return 0;
}
