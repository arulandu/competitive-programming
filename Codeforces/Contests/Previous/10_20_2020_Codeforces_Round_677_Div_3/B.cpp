#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int s = -1;
    int c = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      if(x == 1){
        if(s >= 0){
          c += i-s-1;
          s = -1;
        }

        s = i;
      }
    }

    cout << c << '\n';
  }
  return 0;
}

/*
[0, 1, 1, 0, 1] - number of 0s between 2 1s
[0, 1, 1, 0, 1, 0, 0, 1]
[0, 1, 0, 1, 0, 0, 1]
# Idea: count the number of 0s between 2 1s
*/
