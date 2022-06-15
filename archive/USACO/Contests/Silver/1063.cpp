/*
Contest: USACO 2020 December Silver
Problem: #2 Rectangular Pasture
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[2500][2500];

int sum(int x1, int y1, int x2, int y2){
  return dp[x2][y2]-(y1 ? dp[x2][y1-1] : 0)-(x1 ? dp[x1-1][y2] : 0) + (x1&&y1? dp[x1-1][y1-1] : 0);
}

int main(){
  int n; cin >> n;
  vector<pair<int, int>> cows(n);
  for(int i = 0; i < n; i++){
    cin >> cows[i].first >> cows[i].second;
  }  

  // coord compress
  sort(cows.begin(), cows.end(), [](auto &c1, auto &c2){
    return c1.second < c2.second;
  });
  for(int i = 0; i < n; i++) cows[i].second = i;
  sort(cows.begin(), cows.end(), [](auto &c1, auto &c2){
    return c1.first < c2.first;
  });
  for(int i = 0; i < n; i++) cows[i].first = i;

  // leave cows in increasing x-coord order

  // update prefix w init vals
  for(int i = 0; i < n; i++)
    for(int j= 0; j < n; j++)
      dp[i][j] = cows[i].second == j;

  // propagate prefix
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i) dp[i][j] += dp[i-1][j];
      if(j) dp[i][j] += dp[i][j-1];
      if(i&&j) dp[i][j] -= dp[i-1][j-1];
    }
  }

  ll c = 1; // add null set

  // two pointers to bound left/right sides of rect (x-vals)
  for(int x1 = 0; x1 < n; x1++){
    for(int x2 = x1; x2 < n; x2++){
      // since coords are distinct, # of subsets = # of points to left of left side * # of points to right of right side
      c += sum(x1, 0, x2, min(cows[x2].second, cows[x1].second))*sum(x1, max(cows[x1].second, cows[x2].second), x2, n-1);
    }
  }

  cout << c << '\n';

  return 0;
}