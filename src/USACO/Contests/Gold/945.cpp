/*
Contest: USACO Gold US Open 2019
Problem: [1] Snakes
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

const int inf = 1e9;
const int MAXN = 400;
const int MAXK = MAXN;
int dp[MAXK][MAXN];

// Complexity: O(k*n^2)
int main(){
  io(true, "snakes");

  int N, K; cin >> N >> K; K++;
  vector<int> v(N); for(int i = 0; i < N; i++) cin >> v[i];

  // set initial dp (possible inital bag size)
  for(int k = 0; k < K; k++){
    int mx = -1, sm = 0;
    for(int j = 0; j < N; j++){
      dp[k][j] = inf;
      if(k == 0 && v[j] >= mx){
        dp[k][j] = min(dp[k][j], j*v[j]-sm);
      }

      mx = max(mx, v[j]); sm += v[j];
    }
  }

  for(int k = 0; k < K; k++){
    if(k > 0){
      for(int j = 0; j < N; j++){
        if(dp[k-1][j] == inf) continue;
      
        // transition idek
        int mx = -1, sm = 0;
        for(int nj = j+1; nj < N; nj++){
          if(v[nj] >= mx) dp[k][nj] = min(dp[k][nj], dp[k-1][j]+(nj-(j+1))*v[nj]-sm);
          sm += v[nj]; mx = max(mx, v[nj]);
        }
      }
    }
    
    // propagate dp for (nj = j+1 <-> end) as long as current bag, of size v[j], can satisfy between
    int tmp[N]; for(int j = 0; j < N; j++) tmp[j] = dp[k][j];

    for(int j = 0; j < N; j++) {
      if(dp[k][j] == inf) continue;

      int s = tmp[j];
      for(int nj = j+1; nj < N; nj++){
        if(v[j] < v[nj]) break;
        s += v[j]-v[nj];
        dp[k][nj] = min(dp[k][nj], s);
      }
    }
  }

  cout << dp[K-1][N-1] << '\n';

  return 0;
}
