/*
Contest: Codeforces Round #816 (Div.2)
Problem: [D] 2+ Doors 
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXB = 31;
const int MAXN = 1e5, MAXQ = 2e5;
vector<pair<pair<int, int>, int>> stats(MAXQ); // statements
vector<vector<pair<int, int>>> adj(MAXN); // graph
vector<int> forced(MAXN, -1); // bit by bit answer
stack<int> st; // stack for dfs

// force and push onto stack
void push(int i, int v){
  if(forced[i] == -1){
    forced[i] = v; st.push(i);
  }
}

// propagate constraints
void propagate(int b){
  while(!st.empty()){
    int j = st.top(); st.pop();
    for(auto edge : adj[j]){
      bool zero = ((edge.second >> b) & 1) == 0;
      if(forced[j] == 0 && !zero){
        push(edge.first, 1); // if one edge connects 0 and X, then X = 1.
      } else if(forced[j] == 1 && zero){
        assert(false); // impossible
      }
    }
  }
}

// O(B*(N+Q))
void solve(){
  // read input
  int n, q; cin >> n >> q;
  for(int k = 0; k < q; k++){
    cin >> stats[k].first.first >> stats[k].first.second >> stats[k].second;
    stats[k].first.first--; stats[k].first.second--;
  }

  // build weighted graph
  for(int i = 0; i < q; i++) {
    auto stat = stats[i];
    adj[stat.first.first].push_back({stat.first.second, stat.second});
    adj[stat.first.second].push_back({stat.first.first, stat.second});
  }
  
  // solve bit by bit
  vector<int> a(n, 0);
  for(int b = 0; b < MAXB; b++){
    // reset stacked and forced array
    while(!st.empty()) st.pop();
    for(int i = 0; i < n; i++) forced[i] = -1;
    
    for(int i = 0; i < q; i++){
      auto stat = stats[i];
      if(((stat.second >> b)&1) == 0) {
        // set 0 edges
        push(stat.first.first, 0);
        push(stat.first.second, 0);
      } else if(stat.first.first == stat.first.second){
        // set 1 loopback edges
        push(stat.first.first, 1);
      }
    }

    // propagate init constraints
    propagate(b);

    // greedily choose 0s and propagate
    for(int i = 0; i < n; i++){
      if(forced[i] == -1){
        push(i, 0);
        propagate(b);
      }
    }
    
    // move to answer
    for(int i = 0; i < n; i++){
      a[i] += (forced[i] << b);
    }
  }

  for(auto x : a) cout << x << ' '; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  while(t--) solve();

  return 0;
}
