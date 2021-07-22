#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2500;
int N, prefix[MAXN+1][MAXN+1];
vector<pair<ll, ll>> ar (MAXN);

// take 2D prefix sum
ll psum(int x1, int y1, int x2, int y2){
  return prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1];
}

int main(){
  // handle fast io
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // read input
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> ar[i].first >> ar[i].second;
  }
  
  // compress x
  sort(ar.begin(), ar.begin()+N, [](const pair<ll, ll> &p1, pair<ll, ll> &p2){
    return p1.first < p2.first;
  });
  for(int i = 0; i < N; i++){
    ar[i].first = i+1;
  }
  
  // compress y
  sort(ar.begin(), ar.begin()+N, [](const pair<ll, ll> &p1, pair<ll, ll> &p2){
    return p1.second < p2.second;
  });
  for(int i = 0; i < N; i++){
    ar[i].second = i+1;
  }
  
  // update prefix with values
  for(int i = 0; i < N; i++){
    prefix[ar[i].first][ar[i].second] = 1;
  }
  
  // calculate sums
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
    }
  }

  // sum (posibilites for left point * possibilities for right point) with fixed top and bottom points
  ll ans = 0;
  for(int i = 1; i <= N; i++){
    for(int j = i; j <= N; j++){
      int minX = min(ar[i-1].first, ar[j-1].first);
      int maxX = max(ar[i-1].first, ar[j-1].first);
      ans += psum(1, i, minX, j)*psum(maxX, i, N, j);
    }
  }

  cout << ans+1 << '\n'; // add null set
  
  return 0;
}