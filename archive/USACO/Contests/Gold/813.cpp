/*
Contest: USACO 2018 February Gold
Problem: #1 Snow Boots
*/

#include <bits/stdc++.h>
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

struct Tile {
  ll p, s; // pos, snow
};

struct Boot {
  ll s, d, p; // snow tol, step size, pos
};

int main(){
  io(true, "snowboots");
  
  // read input
  int n, b; cin >> n >> b;
  vector<Tile> tls(n); for(int i = 0; i < n; i++){ cin >> tls[i].s; tls[i].p = i; }
  vector<Boot> bts(b); for(int i = 0; i < b; i++){ cin >> bts[i].s >> bts[i].d; bts[i].p = i; }

  // sort decreasing snow tol / snow amount
  sort(tls.begin(), tls.end(), [](auto& t1, auto& t2){
    return t1.s > t2.s;
  });
  sort(bts.begin(), bts.end(), [](auto& b1, auto& b2){
    return b1.s > b2.s;
  });

  // nxt/prev [linked list] | previous and next walkable step from i
  int nxt[n], prev[n]; for(int i = 0; i < n; i++){ nxt[i] = i+1; prev[i] = i-1; }
  bool val[b]; // ans
  
  // iterate through boots in decreasing snow tol
  int t = 0; int mxs = 1;
  for(auto& bt : bts){
    // remove tiles snowiest tiles that can't be stepped on from linked list
    while(t < tls.size() && tls[t].s > bt.s){
      nxt[prev[tls[t].p]] = nxt[tls[t].p];
      prev[nxt[tls[t].p]] = prev[tls[t].p];

      // calculate the step size required to avoid this tile (next reachable - previous reachable)
      mxs = max(mxs, nxt[tls[t].p]-prev[tls[t].p]);
      t++;
    }

    // boots can do step size, good
    val[bt.p] = mxs <= bt.d;
  }

  for(int i = 0; i < b; i++) cout << val[i] << '\n';

  return 0;
}
