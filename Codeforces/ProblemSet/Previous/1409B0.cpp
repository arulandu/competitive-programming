#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    int d;
    if(a < b){
      d = min(a-x, n);
      a -= d;
      n -= d;

      d = min(b-x, n);
      b -= d;
      n -= d;
    } else {
      d = min(b-x, n);
      b -= d;
      n -= d;

      d = min(a-x, n);
      a -= d;
      n -= d;
    }

    cout << a*b << endl;
  }

  return 0;
}

/*
  x*y = xy
  x*(y-1) = xy - x
  (x-1)*y = xy - y

*/
