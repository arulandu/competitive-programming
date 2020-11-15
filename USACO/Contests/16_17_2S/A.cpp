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
  int n;
  cin >> n;
  ll ar[n];
  for(int i = 0; i < n; i++){
    cin >> ar[i];
  }

  ll p[n];
  for(int i = 0; i < n; i++){
    if(i == 0){
      p[i] = ar[i] % 7;
    } else {
      p[i] = (ar[i] + p[i-1]) % 7;
    }
  }




  return 0;
}

/*
no sorting, no binary search
3 5 1 6 2 14 10
3 5 1 6 2 0  3
prefix sums => get sum of each subarray
3 8 9 15 17 17 20
3 1 2 1 3 3 6


1, 2, 3 .... N += => N(N+1)/2
N <= 5x10^4
N(N+1)/2 => N^2/2 => 25x10^8 / 2 => 1.3 x 10^9



*/
