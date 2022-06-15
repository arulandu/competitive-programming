#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;
#define ll long long
 
struct Word {
  map<int, int> m; // char-int, count
  string s;
};
 
void solve(){
  int n; cin >> n;
  vector<Word> v(n);

  // read input
  for(int i = 0; i < n; i++){
    cin >> v[i].s;
    for(int t = 0; t < 5; t++){
      v[i].m[t] = 0;
    }
    for(auto c : v[i].s){
      int j = c-'a';
      v[i].m[j]++;
    }
  }
  
  // max over max words per target char
  int mx = 0;
  for(int t = 0; t < 5; t++){
    int c = 0;
    int df = 0;

    // sort asc. by target - other count
    sort(v.begin(), v.end(), [&](const Word &w1, const Word &w2){
      return 2*w1.m.at(t) - (int)w1.s.size() > 2*w2.m.at(t)-(int)w2.s.size();
    });

    // include words if not invalid
    for(int i = 0; i < n; i++){
      int tmp = df;
      df += 2*v[i].m.at(t) - (int)v[i].s.size();
      if(df <= 0){
        df = tmp;
        break;
      } else {
        c++;
      }
    }
    mx = max(mx, c);
  }
 
  cout << mx << '\n';
}
 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int t; cin >> t;
  while(t--){
    solve();
  }
 
  return 0;
}