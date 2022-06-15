#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;
  vector<int> v(n);
  map<int, int> mc;

  for(int i = 0; i < n; i++){
    cin >> v[i];

    if(mc.count(v[i]) == 0){
      mc[v[i]] = 0;
    }
    mc[v[i]]++;
  }

  // cout << "counts\n";
  int c = 0;
  for(auto p : mc){
    // cout << p.first << ' ' << p.second << '\n';
    c += min(p.second, k);
  }
  // cout << '\n';

  map<int, stack<int>> mk;
  int ki = 1;
  for(auto p : mc){
    // cout << p.first << ' ' << p.second << '\n';
    stack<int> s;
    for(int i = 0; i < min(p.second, k); i++){
      if(c < k+1-ki){
        break;
      }

      // cout << ki << ' ';

      s.push(ki);
      ki++;
      if(ki > k){
        ki = 1;
      }
      c--;
    }

    // cout << "| " << ki << '\n';
    mk[p.first] = s;
  }

  for(auto x : v){
    stack<int> &s = mk[x];
    if(s.empty()){
      cout << 0 << ' ';
    } else {
      cout << mk[x].top() << ' ';
      mk[x].pop();
    }
  }
  cout << '\n';
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
