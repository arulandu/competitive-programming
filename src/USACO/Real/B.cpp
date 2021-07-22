#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MAXV = 1e9;
int N, ans;
vector<int> ar (7);

bool check(int a, int b, int c){
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(a+b);
    s.insert(a+c);
    s.insert(b+c);
    s.insert(a+b+c);

    for(int i = 0; i < N; i++){
        if(!(s.count(ar[i]) > 0)) return false;
    }

    return true;

}

void brute(){
    sort(ar.begin(), ar.begin() + N, greater<>());
    ll mx = ar[0];
    for(ll a = 1; a < mx; a++){
        for(ll b = a; b < mx; b++){
            for(ll c = b; c < mx; c++){
                ans += check(a, b, c);
            }
        }
    }
}

void solve(){
    if(N == 7){
        sort(ar.begin(), ar.begin() + N, greater<>());
        ans += check(ar[0]-ar[1], ar[0]-ar[2], ar[1]+ar[2]-ar[0]);
    } else if(N == 6){
        
    } else if(N == 5){

    } else if(N == 4){
        sort(ar.begin(), ar.begin() + N, greater<>());
        
        // A+B, A+C, B+C, A+B+C case
        ans += check(ar[0]-ar[1], ar[0]-ar[2], ar[0]-ar[3]);

        // A is in the sequence WLOG
        
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> ar[i];
        }
        // solve();
        brute();
        cout << ans << '\n';
    }
    return 0;
}