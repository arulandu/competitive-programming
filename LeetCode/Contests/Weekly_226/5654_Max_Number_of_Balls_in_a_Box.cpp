#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDigits(int x){
  int s = 0;
  while(x != 0){
    s += x%10;
    x /= 10;
  }
  return s;
}

int countBalls(int lowLimit, int highLimit) {
  map<int, int> m; // box # to count
  int s;
  for(int i = lowLimit; i <= highLimit; i++){
    s = sumDigits(i);
    if(m.count(s) > 0){
      m[s] += 1;
    } else {
      m[s] = 1;
    }
  }

  int mx = INT_MIN;
  for(auto p : m){
    mx = max(mx, p.second);
  }
  return mx;
}
};