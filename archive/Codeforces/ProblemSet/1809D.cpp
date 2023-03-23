/*
Contest: Educational Codeforces Round 145 
Problem: [D] Binary String Sorting
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll C = 1e12;
void solve(){
  string s; cin >> s; ll n = s.size();
  vector<ll> v;
  ll cnt = 0;
  for(ll i = 0; i < n; i++){
    if(s[i] == '1' && i == 0) v.push_back(0);
    cnt++;
    if(i < n-1 && s[i] != s[i+1]) {
      v.push_back(cnt); cnt = 0;
    }
  }
  if(cnt > 0) v.push_back(cnt);



  ll c = 0; bool b = true;
  for(ll j = 1; j < v.size(); j += 2) {
    // cout << "j: " << j << " | "; 
    // for(auto x : v) cout << x << ' '; cout << '\n';
    if(j < v.size()-1){
      if(b && v[j+1] >= v[j] && v[j+1] > 1){
        // cout << "delete " << j << '\n';
        c += (C+1)*v[j]; // delete the 1 and move on
      } else {
        // swap or delete zeros?
        if(v[j] == 1){
          // cout << j << " swap thru " << j+1 << '\n';
          c += C*v[j+1]; // swap
          if(j+2 < v.size()) v[j+2] += v[j];
        } else {
          c += (C+1)*v[j+1]; // delete block
          // cout << "delete " << j+1 << '\n';
          if(j+2 < v.size()) v[j+2] += v[j];
        }
      }
    }
  }
  cout << c << "\n";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
