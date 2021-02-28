#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3;
int N;
int grid[MAXN+1][MAXN+1];

// O(3*N^2) => O(N^2)
int main(){
    // read input
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[j][i];
        }
    }
    
    // calculate max beaty with horizontal alternating
    ll hmax = 0;
    for(int i = 0; i < N; i++){
        ll sum[2];
        sum[0] = 0;
        sum[1] = 0;

        // update sum[0] and sum[1] (the two possible alternating sums)
        for(int j = 0; j < N; j++){
            sum[j%2] += grid[i][j];
        }

        // use the max
        hmax += max(sum[0], sum[1]);
    }

    // repeat process for vertical alternating
    ll vmax = 0;
    for(int j = 0; j < N; j++){
        ll sum[2];
        sum[0] = 0;
        sum[1] = 0;
        for(int i = 0; i < N; i++){
            sum[i%2] += grid[i][j];
        }
        vmax += max(sum[0], sum[1]);
    }

    // output max of both alternating types
    cout << max(hmax, vmax) << '\n';


    return 0;
}
