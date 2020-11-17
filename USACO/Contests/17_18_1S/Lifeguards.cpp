#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

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

bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2){
  return p1.first < p2.first;
}

int main(){
  handle_io(true, "lifeguards");

  // read input
  int n;
  cin >> n;
  vector<pair<ll, ll>> g (n);
  for(int i = 0; i < n; i++){
    cin >> g[i].first >> g[i].second;
  }

  // sort by start
  sort(g.begin(), g.end(), cmp);

  // calculate total time covered
  ll mr = 0;
  ll s = 0;
  for(int i = 0; i < n; i++){
    if(g[i].second > mr) {
      s += g[i].second - max(g[i].first, mr);
      mr = g[i].second;
    }
  }

  // get minimum time one lifeguard is alone
  mr = 0;
  ll mv = 2e18;
  for(int i = 0; i < n; i++){
    ll l = max(mr, g[i].first);
    ll r = (i==n-1 ? g[i].second : min(g[i+1].first, g[i].second));
    mv = min(mv, r-l);
    mr = max(mr, g[i].second);
  }

  // return total_time - min_alone_time
  mv = max((ll)0, mv);
  cout << s-mv << '\n';

  return 0;
}
