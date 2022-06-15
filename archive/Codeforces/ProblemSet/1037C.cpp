#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string a, b; cin >> a >> b;

  int c = 0;
  for(int i = 0; i < n; i++){
    if(a[i] != b[i]){
        // swap consecutive
        if(a[i+1] != b[i+1] && a[i+1] != a[i]){
            c++;
            i++;
            continue;
        }
        c++; // invert
    }
  }

  cout << c << '\n';
  return 0;
}
