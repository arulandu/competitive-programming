/*
Contest: USACO 2019 February Silver
Problem: [3] The Great Revegetation
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long

void io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

int main(){
  io(true, "revegetate");
  // io(false);

  int n, m; cin >> n >> m;
  vector<pair<int, bool>> adj[n];
  for(int i = 0; i < m; i++){
    char c; int a, b; cin >> c >> a >> b; a--; b--;
    adj[a].push_back({b, c == 'S'});
    adj[b].push_back({a, c == 'S'});
  }

  // for(int i = 0; i < n; i++){
  //   cout << i << " | "; for(auto p : adj[i]) cout << p.first << (p.second ? '.' : '!') << " "; cout << '\n';
  // }

  vector<int> col(n, 0), cmp(n, -1);

  function<bool(int, int, int)> dfs = [&dfs, &adj, &col, &cmp](int r, int c, int v){
    // cout << "dfs | " << r << ' ' << c << ' ' << v << "\n";
    if(col[r] != 0 && col[r] != v) return false;
    
    cmp[r] = c; col[r] = v;

    for(auto p : adj[r]){
      int vp = p.second ? v : -v;
      if(cmp[p.first] == -1) {
        if(!dfs(p.first, c, vp)) return false;
      } else if(col[p.first] != 0 && col[p.first] != vp){
        return false;
      }
    }

    return true;
  };

  int c = 0;
  for(int i = 0; i < n; i++){
    if(cmp[i] == -1){
      if(!dfs(i, ++c, 1)){
        cout << '0' << '\n';
        return 0;
      }
    }
  }

  cout << '1'; for(int i = 0; i < c; i++) cout << '0'; cout << '\n';
  

  return 0;
}
