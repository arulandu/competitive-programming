/*
Contest: Codeforces Global Round18
Problem: [C] Menorah
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n; cin >> n;
  string s1, s2; cin >> s1 >> s2;

  set<int> p00, p11, p01, p10;
  for(int i = 0; i < n; i++){
    if(s1[i] == '0'){
      if(s2[i] == '0'){
        p00.insert(i);
      } else {
        p01.insert(i);
      }
    } else {
      if(s2[i] == '0'){
        p10.insert(i);
      } else {
        p11.insert(i);
      }
    }
  }

  int mops = p01.size() == p10.size() ? p01.size()*2 : INT_MAX;
  for(int i = 0; i < n; i++){
    if(s2[i] == '1'){
      int c01 = p01.count(i) ? p00.size()+1 : p00.size();
      int c10 = p11.count(i) ? p11.size()-1 : p11.size();
      mops = min(mops, c01 == c10 ? 1+c01*2 : INT_MAX);
    }
  }

  return mops == INT_MAX ? -1 : mops;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
