#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> r(n); for(int i = 0; i < n; i++) cin >> r[i];
  vector<int> rs(r.begin(), r.end());

  // sort and binary search + iterators
  sort(rs.begin(), rs.end());
  for(auto x : r){
    auto it = upper_bound(rs.begin(), rs.end(), 2*x);
    int c = -1;
    if(it != rs.begin()) {
      it--;
      if(*it == x){
        if(it != rs.begin()){
          c = *--it;
        }
      } else {
        c = *it;
      }
    }
    cout << c << ' ';
  }
  cout << '\n';
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
