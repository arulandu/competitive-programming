#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 500;
int grid[MAXN][MAXN];
int N;

int fmin(int m){
    bool valr[N]; // if each row is fine
    for(int j = 0; j < N; j++){
        valr[j] = true;
        for(int i = 1; i < N; i++){
            if(grid[j][i] < m){
                valr[j] = false;
                break;
            }
        }
    }

    int c = 0, r = 0;
    for(int j = 0; j < N; j++){
        if(valr[j]){
            r++;
            c += r;
        } 
    }


    return 0;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[j][i];
        }
    }

    int a = fmin(100), b = fmin(101);
    cout << a << ' ' << b;
    cout << a - b << '\n';

    return 0;
}

/*
3
57 120 87
200 100 150
2 141 135
*/
