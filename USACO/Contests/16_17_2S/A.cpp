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

int main(){
    handle_io(true, "maxcross");
    // handle_io(true);

    int N, K, B;
    cin >> N >> K >> B;
    vector<int> ar(B);
    for(int i = 0; i < B; i++){
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    // cout << "ar: ";
    // for(auto a : ar){
    //     cout << a << ' ';
    // }
    // cout << '\n';
    // ar.insert(ar.begin(), 1);
    // ar.push_back(N);
    
    int pref[B];
    pref[0] = ar[0]-1;
    for(int i = 1; i < B; i++){
        pref[i] = pref[i-1] + ar[i]-ar[i-1];
    }
    // pref[B-1] = pref[B-2] + N-ar[B-1]+1;
    // cout << "pref: ";
    // for(int i = 0; i < B; i++){
    //     cout << pref[i] << ' ';
    // }
    // cout << '\n';

    int mn = INT_MAX;
    for(int i = 0; i < B; i++){
        for(int j = i; j < B; j++){
            if(pref[j]-pref[i]-1 >= K){
                // cout << i << ',' << j << '\n';
                mn = min(mn, j-i-1);
            }
        }
    }
    cout << mn << '\n';

    return 0;
}
/*
10 6 5
2
10
1
5
9
--
1  2  5  9  10
1 1  2  5  9  10 10

10
1 10 11 12 13 14 15

*/