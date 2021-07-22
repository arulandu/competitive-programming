#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 5001;
int N, Q;
vector<pair<int, ll>> adj[maxN]; // adj[i] = [pair<node, weight>..]

// handles io
void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

// runs dfs on node and returns num of suggested videos
int dfs(int node, int prev, ll k){
  int c = 1;
  for(auto x : adj[node]){
     // only recurs if weight is larger than k - also prevents recurring to origin
    if(((prev > 0 && x.first != prev) || (prev <= 0)) && x.second >= k){
      c += dfs(x.first, node, k);
    }
  }
  return c;
}

int main(){
  handle_io(true, "mootube");

  // read input and contruct graph
  cin >> N >> Q;
  for(int i = 0; i < N-1; i++){
    int p, q;
    ll r;
    cin >> p >> q >> r;
    adj[p].push_back(make_pair(q, r));
    adj[q].push_back(make_pair(p, r));
  }

  // answer queries with dfs
  for(int i = 0; i < Q; i++){
    ll k;
    int v;
    cin >> k >> v;
    cout << dfs(v, -1, k)-1 << '\n';
  }

  return 0;
}

/*
4 3
1 2 3
2 3 2
2 4 4
1 2
4 1
3 1

3
0
2
PLAN:
1. loop through all pairs and form graph with adj lists
2. dfs from each node and count the number of cows that can be reached
3. find max value of ^
*/
