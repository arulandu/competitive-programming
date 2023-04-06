/*
Contest: Educational Codeforces Round 146 
Problem: [C] Search in Parallel
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, s1, s2; cin >> n >> s1 >> s2;
  
  vector<int> r(n); for(int i = 0; i < n; i++) cin >> r[i];
  vector<pair<int, int>> rp(n); for(int i = 0; i < n; i++) rp[i] = {r[i], i};
  vector<int> a, b;

  // greedy: most freq to least, place in least wait time list
  sort(rp.begin(), rp.end());
  for(int i = n-1; i >= 0; i--){
    int ta = (a.size()+1)*s1, tb = (b.size()+1)*s2;

    if(ta <= tb) {
      a.push_back(rp[i].second);
    } else {
      b.push_back(rp[i].second);
    }
  }

  cout << a.size() << " "; for(auto x : a) cout << x+1 << ' '; cout << '\n';
  cout << b.size() << " "; for(auto x : b) cout << x+1 << ' '; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
