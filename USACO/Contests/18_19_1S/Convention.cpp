#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXT = 1e9;
const int MAXN =  1e5;
bool debug = false;
int N, M, C;
int ar[MAXN];

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

// val is monotonic: false false false ... false true true ... true
bool val(ll t){
    // 2 pointers
    int l = 0;
    int r = 0;
    int m = 0; // stores number of buses needed
    while(l < N){
        // move right pointer
        while(r+1 < N && ar[r+1]-ar[l] <= t && r-l+1 < C){
            r++;
        }
        m++; // add bus

        // move both pointers
        r++;
        l = r;
    }

    // return if # buses m is valid under constraints
    return m <= M;
}

int main(){
    handle_io(true, "convention");

    // read input
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++){
        cin >> ar[i];
    }

    // sort ascending
    sort(ar, ar+N);

    // binary search on max-time from 0 to latest cow arrival
    // to find the least t such that val(t) is true
    ll l = 0;
    ll r = ar[N-1];
    while(l<=r){
        ll t = (l+r)/2;
        if(val(t)){
            r = t-1;
        } else {
            l = t+1;
        }
    }

    cout << l << '\n';

    return 0;
}
