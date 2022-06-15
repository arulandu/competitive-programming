#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

const int MAXN = 500;
ll grid[MAXN][MAXN];
int N; ll E; 

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> E;

  ll mx = LONG_LONG_MIN;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> grid[i][j];
      if(i == 0 || i == N-1|| j == 0 || j == N-1){
        mx =max(mx, grid[i][j]);
      }
    }
  }

  cout << (mx+E) << '\n';

  return 0;
}
