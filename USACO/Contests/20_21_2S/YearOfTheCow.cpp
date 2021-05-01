#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 65536;
int N, K;
ll anc[MAXN+1];
vector<pair<ll, ll>> skips;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> anc[i];
    }
    anc[N] = 0;

    // sort input descending
    sort(anc, anc+N+1, greater<>());

    ll y = anc[0];
    ll c = ceil(anc[0]*1./12)*12-anc[0];
    for(int i = 1; i <= N; i++){
        // get outer multiples of 12 for y and anc[i]
        ll fl = floor(y*1./12)*12, ce = ceil(anc[i]*1./12)*12;

        // update skips and/or count
        if(fl > ce){
            c += y-fl + ce - anc[i];
            y = anc[i];
            skips.push_back(make_pair(ce, fl));
        } else {
            c += y-anc[i];
            y = anc[i];
        }
    }
    
    // sort skips in ascending order of length
    sort(skips.begin(), skips.end(), [](const pair<ll, ll> &p1, const pair<ll, ll> &p2){
        return (p1.second - p1.first) < (p2.second - p2.first);
    });

    // remove the last K-1 skips and count
    for(int i = 0; i < skips.size() - (K-1); i++){
        c += skips[i].second - skips[i].first;
    }

    cout << c << '\n';

    return 0;
}
