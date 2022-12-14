#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool pathExists(int w, int h, vector<vector<int>> &portalArr){
  map<int, vector<pair<int, int>>> c2xy, y2xc;

  sort(portalArr.begin(), portalArr.end(), [](auto &p1, auto &p2){
    if(p1[0] == p2[0]){
      return p1[1] < p2[1];
    } else {
      return p1[0] < p2[0];
    }
  });

  for(auto &portal : portalArr){
    if(c2xy.count(portal[2]) == 0) c2xy[portal[2]] = vector<pair<int, int>>();
    c2xy[portal[2]].push_back({portal[0], portal[1]});
    if(y2xc.count(portal[1]) == 0) y2xc[portal[1]] = vector<pair<int, int>>();
    y2xc[portal[1]].push_back({portal[0], portal[2]});
  }
  
  stack<pair<int, int>> st; st.push({0, 0});
  set<pair<int, int>> vis;
  while(!st.empty()) {
    auto p = st.top(); st.pop();
    if(p.second == h-1) {
      return true;
    }

    if(y2xc.count(p.second) == 1){
      auto it = lower_bound(y2xc[p.second].begin(), y2xc[p.second].end(), make_pair(p.first, -1), [](auto &p1, auto &p2){
        if(p1.first == p2.first){
          return p1.second < p2.second;
        } else {
          return p1.first < p2.first;
        }
      });

      while(it != y2xc[p.second].end()){
        assert(it->first >= p.first);
        for(auto xy : c2xy[it->second]) {
            if(vis.count(xy) == 0){
              st.push(xy);
              vis.insert(xy);
            }
          }
        it++;
      }
    }
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll t = 1;
  cin >> t;
  while(t--) {
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i = 0; i < n; i++){
      cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    cout << (pathExists(w, h, v) ? "true" : "false") << '\n';
  }

  return 0;
}
