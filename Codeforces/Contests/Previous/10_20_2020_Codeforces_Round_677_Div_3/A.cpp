#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int x;
    cin >> x;
    int c = 0;
    c += ((x%10)-1) * 10;
    int d = to_string(x).length();
    c += (d*(d+1))/2;

    cout << c << '\n';
  }

  return 0;
}
