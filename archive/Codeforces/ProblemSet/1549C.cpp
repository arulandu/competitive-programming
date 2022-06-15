#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

const int MAX_NM = 2e5+3;
int weaker[MAX_NM], edges[MAX_NM];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;

  // create graph
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    edges[u]++; edges[v]++;
    weaker[max(v, u)]++;
  }

  // nobles only survive if all friends are weaker than them

  int s = 0; // init answer
  for(int j = 1; j <= n; j++){
    if(weaker[j] == edges[j]) s++;
  }

  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int t; cin >> t;
    if(t == 3){
      cout << s << '\n';
    } else {
      int u, v; cin >> u >> v;
      int si = (weaker[u]==edges[u]) + (weaker[v]==edges[v]);
      if(t == 1){
        weaker[max(v, u)]++;
        edges[v]++; edges[u]++;
      } else {
        weaker[max(v, u)]--;
        edges[v]--; edges[u]--;
      }
      s += (weaker[u]==edges[u]) + (weaker[v]==edges[v]) - si;
    }
  }

  return 0;
}
