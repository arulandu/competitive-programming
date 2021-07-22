#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX = 1e5;
int N, K, L;
vector<int> c(MAX);
vector<int> d(MAX);

// checks if h ind is possible
bool check(int h){
    // cout << "h: " << h << '\n';
    if(h <= 0) return true;

    int x = 0;
    for(int i = 0; i < N; i++){
        d[i] = max(0, h-c[i]);
        if(d[i] == 0) x++;
    }

    sort(d.begin(), d.begin() + N, greater<>());

    int s = 0;
    for(int i = 0; i < h-x; i++){
        s += d[i];
    }

    int k = 0;
    while(s > 0){
        sort(d.begin(), d.begin() + h-x, greater<>());
        // for(int i = 0; i < N; i++){
        //     cout << d[i] << ", ";
        // }
        // cout << '\n';
        for(int i = 0; i < L; i++){
            if(d[i] != 0){
                s--;
                d[i]--;
            }
        }
        k++;
    }
    // cout << "k: " << k << '\n';
    return K >= k;
}

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);

    cin >> N >> K >> L;

    for(int i = 0; i < N; i++){
        cin >> c[i];
    }

    sort(c.begin(), c.begin() + N);

    int l = 1;
    int r = N;
    int m = 0;
    while(l <= r){
        // cout << "lr: " << l << ' ' << r << '\n';
        int h = (l+r)/2;
        if(check(h)){
            l = h+1;
            m = max(m, h);
        } else {
            r = h-1;
        }
    }
    
    cout << m << '\n';

    return 0;
}