#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  map<int, int> ma, mb;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    ma[a[i]] = i;
  }
  for(int i = 0; i < n; i++){
    cin >> b[i];
    mb[b[i]] = i;
  }

  int cl = INT_MAX;
  int c = INT_MAX;
  for(int i = 2*n-1; i > 0; i -= 2){
    // cout << "i: " << i << " cl: " << cl << " c: " << c << "\n";
    cl = min(cl, mb[i+1]);
    c = min(c, cl+ma[i]);
  }

  cout << c << '\n';
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
