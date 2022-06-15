/*
Contest: Codeforces Round #743 (Div. 1)
Problem: [A] Book
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n; cin >> n;

  // build dependencies / required-by lists
  set<int> dep[n], req[n];
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    for(int j = 0; j < x; j++){
      int y; cin >> y; y--;
      dep[i].insert(y); req[y].insert(i);
    }
  }

  set<pair<int, int>> nds; for(int i = 0; i < n; i++) nds.insert({dep[i].size(), i});
  int c = 0, pv = INT_MAX;
  while(!nds.empty()){
    // use lower bound to find next understandable unread chapter
    auto it = nds.begin();
    if(pv != INT_MAX){
      it = nds.upper_bound({0, pv});
      if(it == nds.end() || it->first != 0) it = nds.begin();
    }
    if(it->first > 0) return -1; // not found
    if(it->second <= pv) c++;

    // remove it as a dependency for each node that requires it
    for(auto r : req[it->second]) {
      nds.erase({dep[r].size(), r});
      dep[r].erase(it->second);
      nds.insert({dep[r].size(), r});
    }
    req[it->second].clear();

    // remove
    pv = it->second; nds.erase(it);
  }

  return c;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
