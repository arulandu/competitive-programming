#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vector<int> adj(n, -1);
  set<int> ins[n];
  vector<ll> wt(n, -1);

  ll moo = 0;

  for(int i = 0; i < n; i++){
    int x; cin >> x >> wt[i]; adj[i] = x-1;
    ins[adj[i]].insert(i);
  }
  
  for(int i = 0; i < n; i++) {
    stack<int> st; st.push(i);
    while(!st.empty()){
      int v = st.top(); st.pop();
      if(ins[v].size() == 0 && adj[v] != -1){
        // cout << "set " << v << " " << wt[v] << '\n';
        moo += wt[v]; ins[adj[v]].erase(v); 
        st.push(adj[v]); adj[v] = -1;
      }
    }
  }

  vector<bool> vis(n, false);
  for(int i = 0; i < n; i++){
    if(vis[i] || adj[i] == -1) continue;
    
    stack<int> st; st.push(i);
    ll sm = 0, mn = LONG_LONG_MAX;
    while(!st.empty()){
      int v = st.top(); st.pop();
      // cout << v << " | "; for(auto x : vis) cout << (x ? 'y' : 'n'); cout << '\n';
      if(vis[v] || adj[v] == -1) continue;
      vis[v] = true;
      
      sm += wt[v]; mn = min(mn, wt[v]);
      
      if(!vis[adj[v]]) st.push(adj[v]);
    }
    moo += sm - mn;
  }

  cout << moo << '\n';

    

  return 0;
}

/*
make graph and compute set of "in nodes" for each node
for each node with 0 in nodes, add to permutation / += moos and dfs if buddy now has 0 nodes
the remaining graph should be a set of simple cycles (unproven?)
for each remaining node, dfs the cycle and calc the min val and subtract from sum to get contribution
*/
