/*
Contest: USACO 2018 US Open Silver
Problem: [2] Lemonade Line
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
  io(true, "lemonade");

  // read input and sort w[i] descending
  int n; cin >> n;
  vector<ll> w(n); for(int i = 0; i < n; i++) cin >> w[i];
  sort(w.begin(), w.end(), greater<ll>());

  // simulate
  int c = 0; for(auto wi : w) if(c <= wi) c++;
  cout << c << '\n';

  return 0;
}
