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

int main(){
  handle_io(true, "div7");

  // read input
  int n;
  cin >> n;
  ll ar[n];
  for(int i = 0; i < n; i++){
    cin >> ar[i];
  }

  // calculate prefix sums
  // calc bounds for each distinct residue mod 7 of the largest interval in the prefix sums such that the left and right elements have that residue
  ll p[n];
  map<int, pair<int, int>> m;
  m.insert(make_pair(0, make_pair(-1, -1)));
  for(int i = 0; i < n; i++){
    if(i == 0){
      p[i] = ar[i];
    } else {
      p[i] = p[i-1] + ar[i];
    }
    p[i] %= 7;

    auto itr = m.find(p[i]);
    if(itr == m.end()){
      m.insert(make_pair(p[i], make_pair(i, i)));
    } else {
      itr->second.second = i;
    }
  }

  // get maximum interval length
  int mx = INT_MIN;
  for(auto x : m){
    mx = max(mx, x.second.second - x.second.first);
  }

  cout << mx << '\n';
  return 0;
}
