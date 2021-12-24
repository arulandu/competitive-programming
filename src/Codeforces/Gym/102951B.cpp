/*
Contest: USACO Guide Problem Submission
Problem: [B] Studying Algorithms
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  // read input, sort ascending
  int n, x; cin >> n >> x;
  vector<int> ar(n); for(int i = 0; i < n; i++) cin >> ar[i];
  sort(ar.begin(), ar.end());

  // choose shortest algos first
  int c = 0;
  for(; c < n && x > 0; c++) x -= ar[c];
  if(x < 0) c--;
  cout << c << '\n';

  return 0;
}
