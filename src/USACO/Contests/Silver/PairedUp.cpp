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

// sort ascending by second value in pair
bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2){
    return p1.second < p2.second;
}

int main(){
    handle_io(true, "pairup");

    // read input
    int n;
    cin >> n;
    vector<pair<ll, ll>> v (n);
    for(ll i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    // sort increasing by milk output
    sort(v.begin(), v.end(), cmp);

    ll l = 0; // left pointer starts at beginning
    ll r = n-1; // right pointer starts at end
    ll m = -2e18; // holds maximum time for 1 stall

    // two-pointers method
    while(l < r){
        m = max(m, v[l].second+v[r].second); // update time
        
        // update counts
        ll c = min(v[l].first, v[r].first);
        v[l].first -= c;
        v[r].first -= c;

        // move pointers 
        if(v[l].first <= 0){
            l++;
        }       
        if(v[r].first <= 0){
            r--;
        }
    }

    cout << m << '\n';

    return 0;
}