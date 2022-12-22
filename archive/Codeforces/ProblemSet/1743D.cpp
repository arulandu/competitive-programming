/*
Contest: Educational Codeforces Round 137 (Rated for Div. 2)
Problem: [D] Problem with Random Tests
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  string s; cin >> s;

  // get 0 positions
  vector<int> match;
  for(int i = 0; i < n; i++){
    if(s[i] == '0'){
      match.push_back(i);
    }
  }
  
  for(int mst = 0; mst < match.size(); mst++){ // iterate through start 0
    // bfs
    queue<int> que;
    for(int i = 0; i <= match[mst]; i++){
      que.push(i); 
    }

    for(int j = mst; !que.empty() && j < match.size(); j++){
      int sz = que.size();
      vector<int> v1, v2;
      for(int i = 0; i < sz; i++){
        auto ind = que.front(); que.pop();
        if(s[ind+match[j]-match[mst]] == '1'){
          v1.push_back(ind);
        } else {
          v2.push_back(ind);
        }
      }

      // greedily prune
      if(v1.size() > 0){
        for(auto x : v1) que.push(x);
      } else {
        if(j == mst) break;
        for(auto x : v2) que.push(x);
      }
    }
    
    if(que.size() > 0 || mst == match.size()-1){
      // apply substring
      if(que.size() > 0){
        int f = que.front();
        for(int j = 0; j < n-match[mst]; j++){
          if(s[f+n-match[mst]-1-j] == '1' && s[n-1-j] == '0') s[n-1-j] = '1';
        }
      }
      
      // remove leading 0s
      auto msb = s.find_first_of('1');
      cout << (msb == string::npos ? "0" : s.substr(msb)) << '\n';
      return;
    }
  }
  
  // edge case for all 1s
  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
