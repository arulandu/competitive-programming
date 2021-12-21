/*
Contest: USACO 2016 Open Contest Gold
Problem: #1 Splitting the Field
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
  io(true, "split");
  
  int n; cin >> n;
  vector<pair<ll, ll>> cows(n);
  for(int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;

  // sort by x
  sort(cows.begin(), cows.end(), [](auto &c1, auto &c2){ return c1.first < c2.first; });

  multiset<ll> m;
  for(auto c : cows) m.insert(c.second);

  // use y-multiset and extremal vals in sorted by x to get intial rea
  ll init = (cows[n-1].first-cows[0].first)*(*std::prev(m.end())-*m.begin());

  // iterate through all possible double enclosures with split parallel to y axis
  ll a = LONG_LONG_MAX, lmn = LONG_LONG_MAX, lmx = LONG_LONG_MIN;
  for(int i = 0; i < n-1; i++){
    // as split moves from left to right keep track of max/min of left enclosure
    lmn = min(lmn, cows[i].second); 
    lmx = max(lmx, cows[i].second);

    // use map to get max/min of right enclosure (starts w all points)
    m.erase(m.lower_bound(cows[i].second));

    // minimize area (sum of left and right)
    ll la = (cows[i].first-cows[0].first)*(lmx-lmn);
    ll ra = (cows[n-1].first-cows[i+1].first)*(*std::prev(m.end())-*m.begin());
    a = min(a, la+ra);
  }

  // same thing but split is parallel to the x-axis
  sort(cows.begin(), cows.end(), [](auto &c1, auto &c2){ return c1.second < c2.second; });
  m.clear();
  for(auto c : cows) m.insert(c.first);

  lmn = LONG_LONG_MAX, lmx = LONG_LONG_MIN;
  for(int i = 0; i < n-1; i++){
    lmn = min(lmn, cows[i].first); 
    lmx = max(lmx, cows[i].first);
    m.erase(m.lower_bound(cows[i].first));

    ll la = (cows[i].second-cows[0].second)*(lmx-lmn);
    ll ra = (cows[n-1].second-cows[i+1].second)*(*std::prev(m.end())-*m.begin());
    a = min(a, la+ra);
  }

  // return difference
  cout << init-a << '\n';

  return 0;
}
