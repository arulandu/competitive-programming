/*
Contest: USACO 2017 February Silver
Problem: [1] Why Did The Cow Cross The Road
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
  io(true, "helpcross");

  // sort ascending by [arrival] time
  int c, n; cin >> c >> n;
  vector<ll> ts(c); for(int i = 0; i < c; i++) cin >> ts[i];
  vector<pair<ll, ll>> cs(n); for(int i = 0; i < n; i++) cin >> cs[i].first >> cs[i].second;
  sort(ts.begin(), ts.end());
  sort(cs.begin(), cs.end());

  multiset<int> lvt; // leaving times
  int r = 0, j = 0;
  for(auto t : ts){
    while(j < cs.size() && cs[j].first <= t) lvt.insert(cs[j++].second); // add valid cows
    while(lvt.size() > 0&& *lvt.begin() < t) lvt.erase(lvt.begin()); // remove cows that left
    if(lvt.size() > 0) { r++; lvt.erase(lvt.begin()); } // pair valid cow that leaves the earliest
  }

  cout << r << '\n';

  return 0;
}
