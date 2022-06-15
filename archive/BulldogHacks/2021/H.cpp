#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int n, x, y;

int c = INT_MAX;
void check(int r){
  int m = (n-r)/y;
  c = min(abs(n-(r+m*y)), c);
  c = min(abs(n-(r+m*y+y/2)), c);
  c = min(abs(n-(r+(m+1)*y)), c);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x >> y;

  int r1;
  for(int i = 0; i <= n/x; i++){
    r1 = i*x;    
    check(r1);
    check(r1+x/2);
  }

  cout << c << '\n';

  return 0;
}
