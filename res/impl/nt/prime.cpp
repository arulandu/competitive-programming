/*
Source: CPH
https://usaco.guide/CPH.pdf#page=209
Complexity: O(sqrt(n))
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

template<typename T>
bool prime(T n){
  if(n < 2) return false;
  for(T i = 2; i*i <= n; i++) if(n%i == 0) return false;
  return true;
}

template<typename T>
vector<pair<T, int>> factor(T n){
  vector<pair<T, int>> f;
  for(int i = 2; i*i <= n; i++) {
    int t = 0;
    while(n%i == 0){ n /= i; t++; }
    if(t > 0) f.push_back({i, t}); 
  }
  if(n > 1) f.push_back({n, 1});
  return f; 
}

ll phi(ll x){
  for(auto f : factor(x)){
    x -= x/f.first;
  }
  return x;
}