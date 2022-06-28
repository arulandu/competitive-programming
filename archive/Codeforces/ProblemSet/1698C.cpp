/*
Contest: Codeforces Round #803 (Div. 2)
Problem: [C] 3SUM Closure
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n;
  vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  int pos = 0, neg = 0, zed = 0;
  for(auto x : a){
    if(x > 0) pos++;
    else if(x < 0) neg++;
    else zed++;
  }

  // extremal argument: choose largest 3 and add -> gives an even bigger one not in array
  if(pos >= 3 || neg >= 3) return false;

  // solve problem with array of size max 4
  vector<ll> mini; for(int i = 0; i < neg; i++) mini.push_back(a[i]);
  for(int i = n-1; i > n-1-pos; i--) mini.push_back(a[i]);

  set<ll> ms; for(auto x : mini) ms.insert(x); if(zed > 0) ms.insert(0);
  for(int i = 0; i < mini.size(); i++){
    for(int j = i+1; j < mini.size(); j++){
      if(zed > 0 && ms.count(mini[i]+mini[j]) == 0) return false;
      for(int k = j+1; k < mini.size(); k++){
        if(ms.count(mini[i]+mini[j]+mini[k]) == 0) return false;
      }
    }
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
