#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x, y, z; cin >> x >> y >> z;
  int c = 0;
  for(int i = 0; i <= n/x; i++){
    int r = n-i*x;
    cout << "i: " << i << " r: " << r << '\n';

    for(int j = 0; j <= r/y; j++){
      int r1 = r-j*y;
      cout << "j: " << j << " r1: " << r1 << '\n';

      if(r1 % z == 0){
        cout << "x: " << i << " y: " << j << " z: " << r1/z << " yes " << '\n';
        c++;
      }
    }
  }

  cout << c << '\n';
  return 0;
}
// rock rave