#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int a;
    int b;
    cin >> a;
    cin >> b;

    cout << min(min(a, b), (a+b)/3) << endl;
  }

  return 0;
}
