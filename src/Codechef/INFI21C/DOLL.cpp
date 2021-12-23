#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;
  int c = 0;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    if(x > k) c++;
  }

  cout << c << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while(t--) solve();

  return 0;
}
