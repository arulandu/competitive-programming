/*
Contest: CodeChef Starters 70 Div. 3
Problem: Frequency Array Retrieval
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> bs(n); for(int i = 0; i < n; i++) cin >> bs[i];
  vector<int> as(n, 0);
  map<int, pair<int, int>> mp;
  int e = 1;
  // greedily fill up same freq
  for(int i = 0; i < n; i++){
    if(mp.count(bs[i]) == 0){
      mp[bs[i]] = {e, 0}; e++;
    }
    
    mp[bs[i]].second++;
    as[i] = mp[bs[i]].first;
    // discard if full
    if(mp[bs[i]].second >= bs[i]){
      mp.erase(bs[i]);
    }
  }
  
  // verifys
  map<int, int> freq;
  for(auto x : as) {
    if(freq.count(x) == 0) freq[x] = 0;
    freq[x]++;
  }
  
  for(int i = 0; i < n; i++){
    if(freq[as[i]] != bs[i]){
      cout << -1 << "\n"; return;
    }
  }

  for(auto x : as) cout << x << ' '; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
