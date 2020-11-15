#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

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
  handle_io(true);
  ll n, k;
  cin >> n >> k;
  ll ar[n];
  for(ll i = 0; i < n; i++){
    cin >> ar[i];
  }

  sort(ar, ar+n);

  // for(int i = 0; i < n; i++){
  //   cout << ar[i] << ' ';
  // }
  // cout << '\n';

  ll ms = -2e18;
  ll sum = 0;
  bool started = false;
  // L-R
  for(ll i = 0; i < n-1; i++){
    if(ar[i] >= 0){
      if(ar[i+1]-ar[i] <= k){
        if(!started){
          started = true;
          sum += ar[i]+ar[i+1];
        } else {
          sum += ar[i+1];
        }
      } else {
        if(started){
          break;
        } else {
          continue;
        }
      }
    }
  }

  ms = max(sum, ms);
  sum = 0;
  started = false;

  // R-L
  for(ll i = n-1; i > 0; i--){
    if(ar[i] >= 0){
      if(ar[i]-ar[i-1] <= k){
        if(!started){
          started = true;
          sum += ar[i]+ar[i-1];
        } else {
          sum += ar[i-1];
        }
      } else {
        if(started){
          break;
        } else {
          continue;
        }
      }
    }
  }
  ms = max(sum, ms);
  cout << ms;
  return 0;
}
/*
1 sec
256 MB

[2, 4, 7, 12, 18]

prefer not climbing negative ones

[-5, -2, 1, 3, 7] - k=3

*/
