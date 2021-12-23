/*
Contest: Codeforces Round #696
Problem: [C] Array Destruction
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  // read input and sort ascending
  int n; cin >> n;
  vector<int> v(2*n); for(int i = 0; i < 2*n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  
  // checks if x is possible
  auto ck = [&](int x) -> vector<int>{
    vector<int> fnl;

    multiset<int> ms; for(auto& a : v) ms.insert(a);
    for(int i = 0; i < n; i++){
      // the largest element in the remaining set (*lit) must be in the next delete
      auto lit = prev(ms.end()); int ov = x-*lit; // find complement
      
      // if complement is alr taken, invalid
      ms.erase(lit); auto oit = ms.find(ov);
      if(oit == ms.end()) return {};

      // update x w *lit = x-ov
      fnl.push_back(ov); fnl.push_back(x-ov);
      ms.erase(oit); x = x-ov; 
    }

    return fnl;
  };
  
  // check all possible x = largest + other
  for(int j = 0; j < 2*n-1; j++){
    int x = v[2*n-1]+v[j];
    vector<int> g = ck(x);
    if(g.size() == 2*n){
      cout << "YES\n";
      cout << x << '\n';
      for(int i = 0; i < n; i++){
        cout << g[2*i] << ' ' << g[2*i+1] << '\n';
      }

      return;
    }
  }

  cout << "NO\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t; while(t--) solve();

  return 0;
}
