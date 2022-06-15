/*
Contest: USACO 2020 January Silver
Problem: [1] Berry Picking
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

int main(){
  io(true, "berries");

  // read input sort trees by descending #
  int n, k; cin >> n >> k;
  vector<int> ts(n); for(int i = 0; i < n; i++) cin >> ts[i];
  sort(ts.begin(), ts.end(), greater<int>());
  
  int mx = INT_MIN; for(auto b : ts) mx = max(mx, b);

  // try to fill baskets with at most b
  int best = 0;
  for(int b = 1; b <= mx; b++){
    // # of full baskets
    int f = 0; for(auto t : ts) f += t/b;
    if(f < k/2) break; // stop search if essie didn't fill

    int c = 0;
    if(f >= k) {
      c = b*k/2;
    } else {
      // place trees with largest remainders < b into baskets
      sort(ts.begin(), ts.end(), [&](auto& t1, auto& t2){ return t1%b > t2%b;});
      c = b*(f-k/2);
      for(int i = 0; i < ts.size() && (i+f) < k; i++) c += ts[i]%b;
    }

    best = max(best, c);
  }

  cout << best << '\n';

  return 0;
}
