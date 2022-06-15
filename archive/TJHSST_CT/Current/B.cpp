#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.second < p2.second;
  };

  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
  
  ll ls = 0;
  for(int i = 0; i < n; i++){
    string s; int c; ll p; cin >> s >> c >> p;
    if(s == "BUY"){
      // cout << s << '\n';
      pq.push({c, p});
    } else {
      while(c > 0){
        pair<int, int> t = pq.top();
        // cout << t.first << ' ' << t.second << '\n';
        pq.pop();
        int m = min(c, t.first);
        if(m < t.first){
          pq.push({t.first-m, t.second});
        }
        c -= m;
        ls -= (t.second-p)*m;
      }
    }
  }

  cout << ls << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
