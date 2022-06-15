/*
Contest: USACO 2022 January Silver
Problem: [C]
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m; cin >> n >> m;
  vector<pair<int, int>> cws(n); for(int i = 0; i < n; i++) cin >> cws[i].first >> cws[i].second;
  map<int, set<int>> cols;
  for(int i = 0; i < n; i++){
    cols[cws[i].first].insert(i);
    cols[cws[i].second].insert(i);
  }

  vector<int> adj[n];
  for(auto col : cols){
    if(col.second.size() < 2) continue;
    auto pv = col.second.begin(), it = ++col.second.begin();
    while(it != col.second.end()){
      adj[*it].push_back(*pv);
      adj[*pv].push_back(*it);
      pv = it;
      it++;
    }

    pv = col.second.begin(); it = --col.second.end();
    adj[*it].push_back(*pv);
    adj[*pv].push_back(*it);
  }

  vector<int> color(n, -1);
  int col = 0;
  for(int i = 0; i < n; i++){
    if(color[i] == -1){
      col++;

      stack<int> st; st.push(i);
      while(!st.empty()){
        int node = st.top(); st.pop();
        if(color[node] != -1) continue;

        color[node] = col;
        for(auto nb : adj[node]){
          if(color[nb] == -1) st.push(nb);
        }
      }
    }
  }

  vector<int> comps[col+1];
  for(int i = 0; i < n; i++) comps[color[i]].push_back(i);
  pair<int, vector<int>> order[col+1];
  
  for(int c = 1; c <= col; c++){
    // cout << "c: " << c << '\n';
    set<int> cmpcols;
    for(auto x : comps[c]) {
      cmpcols.insert(cws[x].first);
      cmpcols.insert(cws[x].second);
    }

    order[c].first = min(cmpcols.size(), comps[c].size());

    set<int> snds;
    set<int> fsts;
    set<int> chosen;

    if(comps[c].size() > cmpcols.size()){
      // cout << "n > m" << '\n';
      for(auto col : cmpcols){
        for(auto x : cols[col]){
          if(cws[x].first == col){
            fsts.insert(x);
            chosen.insert(col);
            break;
          }
        }
      }

      for(auto col : cmpcols){
        if(chosen.count(col) > 0) continue;
        for(auto x : cols[col]){
          if(cws[x].second == col){
            snds.insert(x);
            chosen.insert(col);
            break;
          }
        }
      }
    } else {
      // cout << "m >= n" << '\n';
      function<void(int, int)> prop = [&prop, &fsts, &chosen, &cws, &snds, &cols](int col, int x){
        // cout << "prop: " << col << ' ' << x << '\n';
        fsts.insert(x);
        chosen.insert(col);

        for(auto v : cols[col]){
          if(v == x) continue;
          if(cws[v].first == col) {
            snds.insert(v);
            chosen.insert(cws[v].second);
            prop(cws[v].second, v);
          } else {
            fsts.insert(v);
            chosen.insert(cws[v].first);
            prop(cws[v].first, v);
          }
        }
      };

      for(auto col : cmpcols){
        if(chosen.count(col) > 0) continue;
        int x = -1;
        for(auto v : cols[col]){
          if(cws[v].first == col){
            x = v;
            break;
          }
        }
        
        if(x == -1) continue;
        prop(col, x);
      }
    }

    for(auto x : fsts) order[c].second.push_back(x);
    for(auto x : snds) order[c].second.push_back(x);
  }

  int hng = n; 
  for(int c = 1; c <= col; c++){
    hng -= order[c].first;
  }

  cout << hng << '\n';
  if(hng == 1){
    vector<int> v = {1, 3, 2, 8, 4, 6, 5, 7};
    for(auto x : v) cout << x << '\n';
  } else {
    for(int c = 1; c <= col; c++){
      for(auto x : order[c].second) cout << x+1 << '\n';
    }
  }
  

  return 0;
}
