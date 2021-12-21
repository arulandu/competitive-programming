#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class SegmentTree {
  int n;
  vector<int> lo, hi, min, delta;

  public:
  SegmentTree(int n) : n(n), lo(4*n+1), hi(4*n+1), min(4*n+1), delta(4*n+1) {
    init(1, 0, n-1);
  }
  

  void init(int i, int a, int b){
    lo[i] = a;
    hi[i] = b;

    if(a == b) return;

    int m = (a+b)/2;
    init(2*i, a, m);
    init(2*i+1, m+1, b);
  }
  

};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}
