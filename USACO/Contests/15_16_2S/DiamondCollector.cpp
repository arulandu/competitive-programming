#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main(){
    handle_io(false, "diamond");

    // read input
    int n;
    ll k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    // sort ascending in size
    sort(v.begin(), v.end());

    int c[n]; // c[i] - the amount of diamonds in a bag with smallest element v[i]
    int l = 0; // left pointer
    int r = 0; // right pointer
    for(;l < n; l++){
        // move right pointer to max satisfying condition
        while(r+1 < n && abs(v[l]-v[r+1]) <= k){
            r++;
        }
        c[l] = r-l+1;
    }

    int ma[n+1]; // max value of c after index i
    ma[n] = 0;
    for(int i = n-1; i >= 0; i--){
        ma[i] = max(c[i], ma[i+1]);
    }
    
    // use max-after array to calc max of 2 bags
    int m = -1;
    for(int i = 0; i < n; i++){
        m = max(m, c[i]+ma[i+c[i]]);
    }

    cout << m << '\n';

    return 0;
}
