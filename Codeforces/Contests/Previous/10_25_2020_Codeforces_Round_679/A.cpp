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
    for(int i = 0; i < n; i += 2){
      int x, y;
      cin >> x >> y;
      cout << y << ' ' << -1*x << ' ';
    }
    cout << '\n';
  }

  return 0;
}

/*
7 6 2 5
6 -7 5 -2
*/
