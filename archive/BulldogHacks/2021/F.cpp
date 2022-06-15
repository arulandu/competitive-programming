#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d; cin >> a >> b >> c >> d;
  ld d1 = sqrtl((a-c)*(a-c)+(b-d)*(b-d));
  ld d2 = fabsl(a-c)+fabsl(b-d);
  ld diff = floor((d2-d1) * 100.0 + .5) / 100.0;
  cout << diff << '\n';

  return 0;
}

// transport task