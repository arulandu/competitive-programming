/*
Contest: Codeforces Round #763 [Div. 2]
Problem: [B] Game on Ranges
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  map<int, multiset<int>> ml, mr;
  vector<pair<int, int>> vls(n); for(int i = 0; i < n; i++) cin >> vls[i].first >> vls[i].second;

  int mn = INT_MAX, mx = INT_MIN;
  for(auto v : vls){
    ml[v.first].insert(v.second);
    mr[v.second].insert(v.first);
    mn = min(mn, v.first); mx = max(mx, v.second);
  }

  // for(auto p : ml){
  //   cout << p.first << " | "; for(auto x : p.second) cout << x << ' '; cout << '\n';
  // }
  // cout << "\n";

  // for(auto p : mr){
  //   cout << p.first << " | "; for(auto x : p.second) cout << x << ' '; cout << '\n';
  // }
  // cout << "\n";

  stack<pair<int, int>> st; 
  ml[mn].erase(ml[mn].find(mx));  
  mr[mx].erase(mr[mx].find(mn));
  st.push({mn, mx});

  while(!st.empty()){
    auto v = st.top(); st.pop();
    // cout << v.first << ' ' << v.second << " | " << '\n';

    int l = -1, r = -1;
    if(ml[v.first].size() > 0) {
      auto it = --ml[v.first].end(); l = *it;
      st.push({v.first, l});
      ml[v.first].erase(it);
      mr[l].erase(mr[l].find(v.first));
    }

    if(mr[v.second].size() > 0) {
      auto it = mr[v.second].begin(); r = *it;
      st.push({r, v.second});
      mr[v.second].erase(it);
      ml[r].erase(ml[r].find(v.second));
    }

    int d = r != -1 ? r-1 : (l != -1 ? l+1 : (v.first == v.second ? v.first  : -1));
    assert(d >= 0);
    // cout << l << " " << r << "\n";
    cout << v.first << ' ' << v.second << ' ' << d << '\n';
  }

  // cout << "done\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
    if(t > 0) cout << '\n';
  }

  return 0;
}
