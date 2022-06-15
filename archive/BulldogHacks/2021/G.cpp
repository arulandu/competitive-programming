#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ld c = (n/60.)*88.53;
  cout << ((int)floorl(c + .5)) << '\n';

  return 0;
}

// diabetic dilemna