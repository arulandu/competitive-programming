#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> ss(n); for(int i = 0; i < n; i++) cin >> ss[i];
  sort(ss.begin(), ss.end());

  int c = 1;
  for(int i = 0; i < n; i++){
    if(c <= ss[i]){
      c++;
    }
  }

  cout << c-1 << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
