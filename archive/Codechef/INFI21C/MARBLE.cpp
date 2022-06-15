#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  string s1, s2; cin >> s1 >> s2;
  set<char> vw = {'a', 'e', 'i', 'o', 'u'};
  int mn = INT_MAX;
  for(char c = 'a'; c <= 'z'; c++){
    int v = 0;
    string p1 = s1, p2 = s2;
    for(int i = 0; i < n; i++){
      if(p1[i] == '?') p1[i] = c;
      if(p2[i] == '?') p2[i] = c;

      if(p1[i] == p2[i]){
        continue;
      } else if(vw.count(p1[i]) != vw.count(p2[i])){
        v++;
      } else {
        v += 2;
      }
    }

    // cout << c << " " << v << '\n';
    mn = min(v, mn);
  }

  cout << mn << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while(t--) solve();

  return 0;
}
