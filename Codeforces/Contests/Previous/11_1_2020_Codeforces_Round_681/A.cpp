#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << 4 << ' ';
    int c = n-1;
    for(int i = 4; i < 4*n; i += 2){
      if(c <= 0){
        break;
      }
      if(i % 4 != 0){
        cout << i << ' ';
        c--;
      }
    }
    cout << '\n';
  }

  return 0;
}

/*
a doesn't divide b and b doesn't divide a, gcd(a,b) is not 1 meaning a, b are not relatively prime and share a factor
n = 6
2, 3, 5, 7, 11, ...
8, 12, 20, 28, 44...
6, 9, 15, 21, 33...

*/
