#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    long p, q;
    cin >> p >> q;
    if (p % q == 0) {
      long d = p / q;
      long xmax = INT_MIN;
      long q1 = q;
      cout << q << ' ' << q1 << ' ';
      for(int i = 2; i < sqrt(q); i++){
        if(q1 % i == 0 && (p / i != q)){
          cout << "x ";
          xmax = max(xmax, p / i);
        }
        while(q1%i==0){
          q1 /= i;
        }
        cout << q << ' ';
      }

      cout << xmax << '\n';

    } else {
      cout << p << '\n';
    }
  }

  return 0;
}

/*
if q | p:
  12, 6 => 12/6=2 => 2
else:
  print q

  24 12
  d = 2
  12 => 4
*/
