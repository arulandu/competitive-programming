#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> ar(n);
  for(int i = 0; i < n; i++){
    cin >> ar[i];
  }

  sort(ar.begin(), ar.end());
  int s = 0;
  for(int i = n-1; i > n-1-k; i--){
    s += ar[i];
  }
  cout << s << '\n';

  return 0;
}
