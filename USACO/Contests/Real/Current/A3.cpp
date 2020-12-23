#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxN = 1e5 + 1;
ll N;
set<ll> adj[maxN];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for(ll i = 0; i < N-1; i++){
    ll a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  int s = rint(ceil(log2(adj[1].size()+1)));
  for(int i = 2; i <= N; i++){
    s += rint(ceil(log2(adj[i].size())));

  }

  cout << s+N-1 << '\n';
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
