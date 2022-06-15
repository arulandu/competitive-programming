/*
Contest: USACO 2019 February Silver
Problem: #2 Painting the Barn
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int M = 1000;

void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

int main(){
  handle_io(true, "paintbarn");

  int n, k; cin >> n >> k;
  int g[M+1][M+1];
  for(int i = 0; i < n; i++){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    // add 2D range update deltas
    g[x1][y1]++; g[x1][y2]--; g[x2][y1]--; g[x2][y2]++;
  }

  // propagate deltas w 2D prefix sums
  int area = 0;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
      if(i > 0) g[i][j] += g[i-1][j];
      if(j > 0) g[i][j] += g[i][j-1];
      if(i > 0 && j > 0) g[i][j] -= g[i-1][j-1];

      // inc if k layers
      if(g[i][j] == k) area++;
    }
  }

  cout << area << '\n';

  return 0;
}
