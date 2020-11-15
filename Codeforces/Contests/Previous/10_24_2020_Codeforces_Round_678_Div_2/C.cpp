#include <bits/stdc++.h>
using namespace std;
#define ll long long


/*
[1, 2, 3, 4], 1
l=0, r=4, m=2
(n-1)! ?

find the number of places the binary search checks before it hits the value - call the num k
return (n-k)!

[4, 1, 2, 3], 1
i=2 forced <= x
i=1 ended

find the number of places -> with index < pos call it c, with index > pos call it d, (x-1)P(c) * (n-x)P(d) * (n-c-d)!

run binary search once to find a, b
calculate

*/

int n, x, pos, c, d;
ll mod = 1e9 + 7;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x >> pos;
  c = 0;
  d = 0;

  int left = 0;
  int right = n;
  while(left < right){
    int middle = (left + right) / 2;

    if(middle < pos){
      c++;
      left = middle + 1;
    } else if(middle > pos){
      d++;
      right = middle;
    } else {
      break;
    }
  }
  // cout << c << ' ' << d << '\n';
  /*
    (x-1)!/(x-1-c)! * (n-x)!/(n-x-d)! * (n-c-d-1)!
  */
  ll p = 1;
  for(int i = 0; i < c; i++){
    p *= (x-i-1);
    p = p % mod;
  }
  for(int i = 0; i < d; i++){
    p *= (n-x-i);
    p = p % mod;
  }
  for(int i = n-c-d-1; i > 1; i--){
    p *= i;
    p = p % mod;
  }

  cout << p << '\n';

  return 0;
}
