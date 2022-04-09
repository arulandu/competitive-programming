#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  string s; cin >> s;
  string o = "";
  int c = 0;
  for(int i = 0; i < s.size(); i++){
    o += s[i];
    if(i < s.size()-1){
      if(s[i] == s[i+1]) {
        c++;
      } else {
        if(s[i] < s[i+1]){
          for(int j = 0; j <= c; j++) o += s[i];
        }
        c = 0;
      }
    }
  }

  cout << o << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
