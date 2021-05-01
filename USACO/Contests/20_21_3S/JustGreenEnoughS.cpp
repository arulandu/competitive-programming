#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 500;
int grid[MAXN][MAXN], pneg[MAXN+1][MAXN+1], pzero[MAXN+1][MAXN+1];
int N;

int prefzero(int xi, int xj, int yi, int yj){
    return pzero[xj][yj] - pzero[xi][yj] - pzero[xj][yi] + pzero[xi][yi];
}

int prefneg(int xi, int xj, int yi, int yj){
    return pneg[xj][yj] - pneg[xi][yj] - pneg[xj][yi] + pneg[xi][yi];
}

bool check(int xi, int xj, int yi, int yj){
    return prefzero(xi, xj, yi, yj) > 0 && prefneg(xi, xj, yi, yj) == 0;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            cin >> x;
            if(x == 100){
                grid[j][i] = 0;
            } else {
                grid[j][i] = x > 100 ? 1 : -1;
            }
        }
    }

    pneg[0][0] = (grid[0][0] == -1);
    pzero[0][0] = (grid[0][0] == 0);
    for(int i = 0; i < N; i++){
        pneg[0][i] = 0;
        pneg[i][0] = 0;
        pzero[0][i] = 0;
        pzero[i][0] = 0;
    }

    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= N; i++){
            pneg[i][j] = (grid[i-1][j-1] == -1) + pneg[i-1][j] + pneg[i][j-1] - pneg[i-1][j-1];
            pzero[i][j] = (grid[i-1][j-1] == 0) + pzero[i-1][j] + pzero[i][j-1] - pzero[i-1][j-1];
        }
    }

    int c = 0;
    for(int xi = 0; xi < N; xi++){
        for(int xj = xi+1; xj <= N; xj++){
            for(int yi = 0; yi < N; yi++){
                for(int yj = yi+1; yj <= N; yj++){
                    int pn = prefneg(xi, xj, yi, yj), pz = prefzero(xi, xj, yi, yj);
                    if(pz > 0 && pn == 0) c++;
                    if(pn > 0) break;
                }
            }
        }
    }

    cout << c << '\n';

    return 0;
}

/*
3
57 120 87
200 100 150
2 141 135
*/
