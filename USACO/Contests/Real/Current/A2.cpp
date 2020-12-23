#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxN = 1e5 + 1;
ll N;
vector<ll> adj[maxN];

int dfs(ll node, bool isStart){
  ll o = adj[node].size() + (isStart?1:-1);
  if(o == 0 || o == 1){
    return o;
  }
  ll c = rint(ceil(log2(o)));
  // cout << "n: " << node << " o: " << o << " c: " << c << '\n';
  for(auto x : adj[node]){
    c += dfs(x, false);
  }
  return c;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for(ll i = 0; i < N-1; i++){
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // for(int i = 1; i <= N; i++){
  //   cout << i << ": ";
  //   for(auto x : adj[i]){
  //     cout << x << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << (dfs(1, true)+N-1) << '\n';
  return 0;
}


/*
4
1 2
1 3
1 4

1 strong component
no cycles

Subtasks:
1-4 => double and then spread
5-7

Idea:
- start at farm 1
- dfs through and add the number of nodes that come out other than the prev => log base 2
- sum ^^ + number of nodes
*/
