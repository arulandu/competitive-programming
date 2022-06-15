#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

bool search(vector<int> &ar, int ti, int i, int s){
  if(i == ti) i++;
  
  if(s == ar[ti]) return true;
  if(i >= ar.size()) return false;

  return search(ar, ti, i+1, s+ar[i]) || search(ar, ti, i+1, s-ar[i]) || search(ar, ti, i+1, s);
}

bool solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  set<int> s;
  for(auto x : a){
    if(s.count(x) == 1) return true;
    s.insert(x);
  }

  for(int i = 0; i < n; i++){
    if(search(a, i, 0, 0)) return true;
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cout << (solve() ? "YES" : "NO") << '\n';
  }

  return 0;
}
