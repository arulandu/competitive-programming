#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int s;
    cin >> s;
    int n = floor(sqrt(s));
    if(n*n != s){
      n += 1;
    }
    cout << n << '\n';
  }

  return 0;
}
