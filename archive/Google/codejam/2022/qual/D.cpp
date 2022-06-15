#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  int fun[n+1]; for(int i = 1; i <= n; i++) cin >> fun[i];
  vector<int> adj[n+1];
  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    adj[x].push_back(i);
  }

  int bst = INT_MIN;
  stack<int> st; st.push(0);
  while(!st.empty()){
    int v = st.top(); st.pop();
    if(v != 0) bst = max(bst, fun[v]);
    for(auto x : adj[v]){
      st.push(x);
    }
  }

  cout << bst << '\n';
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

/*
dfs from abyss (0) out and calculate the max when ending at a terminus
*/
