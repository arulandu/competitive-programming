#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int k; cin >> k;
  int i = 0, c = 0;
  while(c < k){
    i++;
    if(i%3 == 0 || i%10 == 3){

    } else {
      c++;
    }
  }

  cout << i << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
