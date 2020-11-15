#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int c1 = 0;
  int c2 = 0;
  int c3 = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x == 1){
      c1++;
    } else if(x == 2){
      c2++;
    } else if(x == 3){
      c3++;
    }
  }

  int res = c1 + c2 + c3 - max(max(c1, c2), c3);
  cout << res << endl;
  return 0;
}
