/*
Contest: USACO 2017 January Gold
Problem: [2] Hoof, Paper, Scissors
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

int dp[100000][21][3]; // dp[p][q][r] = max # of games won through the p-th game with exactly q switches ending at r

int main(){
  io(true, "hps");

  // read input: move r+1 beats r in mod 3
  int n, k; cin >> n >> k;
  vector<int> mvs(n);
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    if(s == "H"){
      mvs[i] = 0;
    } else if(s == "P"){
      mvs[i] = 1;
    } else if(s == "S"){
      mvs[i] = 2;
    }
  }

  for(int p = 0; p < n; p++){
    for(int q = 0; q <= k; q++){
      for(int r = 0; r < 3; r++){
        dp[p][q][r] = 0;
        if(p >= 1){
          // change gesture to one of the other two
          if(q >= 1){
            dp[p][q][r] = max(dp[p][q][r], dp[p-1][q-1][(r+1)%3]);
            dp[p][q][r] = max(dp[p][q][r], dp[p-1][q-1][(r+2)%3]);
          }

          dp[p][q][r] = max(dp[p][q][r], dp[p-1][q][r]); // keep gesture
        }

        dp[p][q][r] += r == (mvs[p]+1)%3; // does gesture win?
      }
    }
  }

  // find max when p = n-1
  int res = 0;
  for(int q = 0; q <= k; q++){
    for(int r = 0; r < 3; r++) {
      res = max(res, dp[n-1][q][r]);
    }
  }

  cout << res << '\n';

  return 0;
}
