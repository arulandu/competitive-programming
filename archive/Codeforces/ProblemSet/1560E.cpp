#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  string t; cin >> t;
  
  map<char, pair<int, int>> m; // (char, (last occurence, count))
  for(int i = 0; i < t.size(); i++){
    if(m.count(t[i]) == 0){
      m[t[i]] = {i, 0};
    }
    m[t[i]].first = i; m[t[i]].second++;
  }

  vector<pair<char, pair<int, int>>> v;
  for(auto p : m) v.push_back(p);
  sort(v.begin(), v.end(), [](const pair<char, pair<int, int>> &p1, const pair<char, pair<int, int>> &p2){
    return p1.second.first < p2.second.first;
  });

  int l = 0;
  string ord = "";
  for(int i = 0; i < v.size(); i++){
    ord += v[i].first;
    l += v[i].second.second / (i+1);
  }
  string s = t.substr(0, l);
  string tst = "";
  for(auto c : ord){
    tst += s;
    s.erase(remove(s.begin(), s.end(), c), s.end());
  }

  if(tst == t){
    cout << t.substr(0, l) << ' ' << ord << '\n';
  } else {
    cout << -1 << '\n';
  }
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
