/*
Contest: Codechef Starters 54 (Div. 3)
Problem: [E] Departments (Easy Version)
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent = vector<int>(n, -1);
        size = vector<int>(n, 0);
    }

    void make_set(int v){
        if(v < 0 || size[v] > 0){
            return;
        }
    
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v){
        if(parent[v] == -1){
            return -1;
        }

        if(v == parent[v])
            return v;

        int p = find_set(parent[v]);
        parent[v] = p; // path compression
        return p;
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            // union by size
            if(size[a] < size[b]){
                parent[a] = b;
                size[b] += size[a];
            } else {
                parent[b] = a;
                size[a] += size[b];
            }
        }
    }
};

void solve(){
  // read
  int n, k; cin >> n >> k;
  DSU dsu(n+1); 
  set<int> adj[n+1];
  for(int i = 1; i <= k; i++){
    int u, v; cin >> u >> v;
    adj[u].insert(v); adj[v].insert(u);
  }

  for(int i = 1; i <= n; i++) dsu.make_set(i);

  vector<bool> parent(n+1, false);
  vector<bool> visited(n+1, false);
  for(int i = 1; i <= n; i++){
    if(visited[i]) continue;

    auto it = adj[i].begin();
    int a = *it; it++; visited[a] = true; // get first adj

    // for adj of the adj
    for(auto b : adj[a]){
      visited[b] = true;

      // compute overlap btwn adjs
      auto sm = adj[a].size() < adj[b].size() ? a : b;
      auto lg = adj[a].size() < adj[b].size() ? b : a;
      int c = 0, tc = 0;
      for(auto x : adj[sm]) {
        if(adj[lg].count(x) == 1) {c++;}
        if(x != lg) tc++;
      }
      
      if(c == tc){
        // sm is contained inside lg
        dsu.union_sets(sm, lg);
        if(adj[sm].size() != adj[lg].size()) {
          parent[lg] = true; // lg >> sm -> lg is parent
        }
      } else {
        // diff so both are parents
        parent[lg] = true;
        parent[sm] = true;
      }
    }
  } 

  // get info from dsu
  map<int, int> dept; // dsu leader -> dept
  map<int, int> head; // dept -> head
  int d = 0;
  for(int i = 1; i <= n; i++){
    auto l = dsu.find_set(i); 
    assert(l != -1);
    if(dept.count(l) == 0) {
      dept[l] = ++d;
      head[dept[l]] = l;
    }

    if(parent[i]) {
      head[dept[l]] = i;
    }
  }

  // print
  cout << dept.size() << '\n';
  for(int i = 1; i <= n; i++) cout << dept[dsu.find_set(i)] << ' '; cout << '\n';
  for(auto p : head) cout << p.second << ' '; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}

/*
loop through all nodes
for one node
check adjacent nodes
look at the adjacent nodes of one of the adjacent nodes
compare the two
if the adjacent nodes are all the same with like 1 differnece, connect the two in a dsu
if one of them has all the same but they are missing more, then the one with more is the parent
if they both have different then they are both parents
basically find each component and the parent for each one
marked ones that you've assigned already as visited so complexity is good
*/