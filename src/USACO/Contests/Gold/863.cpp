/*
Contest: USACO 2018 December Gold
Problem: [3] Teamwork
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

const int MAXN = 1e4;
int dp[MAXN]; // dp[i] = max sum of skill levels of first i (inclusive)

int main(){
  io(true, "teamwork");

  int n, k; cin >> n >> k;
  vector<int> ss(n); for(int i = 0; i < n; i++) cin >> ss[i];

  for(int i = 0; i < n; i++){
    dp[i] = INT_MIN; int mx = INT_MIN;
    // transitions: loop through size of last team
    for(int r = 1; r <= k; r++){
      if(i-r >= -1) {
        mx = max(mx, ss[i-r+1]); // keep running max of last r cows
        dp[i] = max(dp[i], mx*r+(i-r >= 0 ? dp[i-r] : 0));
      }
    }
  }

  cout << dp[n-1] << '\n';
  return 0;
}
