/*
Contest: USACO 2015 December Silver
Problem: [2] High Card Wins
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
  io(true, "highcard");

  // read input
  int n; cin >> n;
  vector<int> es(n); for(int i = 0; i < n; i++) cin >> es[i];
  set<int> ess; for(auto e : es) ess.insert(e);
  vector<int> bs; for(int i = 1; i <= 2*n; i++) if(!ess.count(i)) bs.push_back(i);

  sort(es.begin(), es.end(), greater<int>());
  sort(bs.begin(), bs.end(), greater<int>());
  
  // two pointers: use bessie's best card on highest elsie card that it can beat
  int i = 0, j = 0, c = 0;
  while(i < bs.size() && j < es.size()){
    while(j < es.size() && es[j] > bs[i]) j++;
    if(j < es.size()) {
      c++; j++; i++;
    }
  }

  cout << c << '\n';
  return 0;
}
