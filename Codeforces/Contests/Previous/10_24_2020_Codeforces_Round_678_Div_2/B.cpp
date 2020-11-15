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
    for(int r = 0; r < n; r++){
      for(int c = 0; c < n; c++){
        if(r==c || (r+1==c) || (r==n-1 && c==0)){
          cout << 1 << ' ';
        } else {
          cout << 0 << ' ';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}

/*
0, 1, 2, 3,

3
1 1 0
0 1 1
1 0 1

4
1 1 0 0
0 1 1 0
0 0 1 1
1 0 0 1

5
1 1 0 0 0
0 1 1 0 0
0 0 1 1 0
0 0 0 1 1
1 0 0 0 1

(r, c)
(4, 0)
(0, 0), (1, 1), (2, 2) --- (r, c)
(0, 1), (1, 2) --- (r, c+1)

*/
