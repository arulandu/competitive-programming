#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // read input and map to index
  int n; cin >> n;
  vector<int> a(n);
  map<int, int> m = {
      {4, 0},
      {8, 1},
      {15, 2},
      {16, 3},
      {23, 4},
      {42, 5},
  };

  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i] = m[a[i]];
  }

  int dp[6]; // dp[i] = number of subsequences with first i+1 elements
  memset(dp, 0, sizeof(dp));
  for(auto x : a){
    // add to prev subsequence if exist or first
    if(x == 0 || dp[x-1] > 0){
        if(x > 0) dp[x-1]--;
        dp[x]++;
    }
  }

  // remove elements not in a complete subseq.
  cout << n-6*dp[5] << '\n';

  return 0;
}
