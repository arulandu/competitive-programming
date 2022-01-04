/*
Contest: Codeforces Hello 2022
Problem: [C] Hidden Permutations
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int qry(int i){
  cout << "? " << i << endl;
  int x; cin >> x; return x;
}

void solve(){
  int n; cin >> n;
  vector<int> pm(n+1, -1);
  auto cyc = [&](int j){
    // cout << "cyc " << j << " | \n";
    int p = qry(j);
    while(pm[p] == -1){
      int v = qry(j);
      pm[p] = v; p = v;
    }
    return p;
  };

  for(int i = 1; i <= n; i++){
    if(pm[i] == -1){
      cyc(i);
    }
  }

  cout << "! "; for(int i = 1; i <= n; i++) cout << pm[i] << ' '; cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
