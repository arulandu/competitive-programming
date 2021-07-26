#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long


int solve(){
  int n; cin >> n;
  vector<vector<int>> stats(n, vector<int>(5, -1));
  vector<int> init(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 5; j++){
      cin >> stats[i][j];
      init[i] = i;
    }
  }

  auto cmp = [&](const int p1, const int p2){
    int c = 0;
    for(int i = 0; i < 5; i++){
      if(stats[p1][i] < stats[p2][i]) c++;
    }
    return c >= 3 ? p1 : p2;
  };

  vector<int>& cur = init;

  while(cur.size() > 1){
    // cout << cur.size() << " cur: ";
    // for(auto x : cur){
    //   cout << x << ' ';
    // }
    // cout << '\n';
    vector<int> nxt((cur.size()+1)/2, -1);
    for(int i = 0; i < cur.size(); i += 2){
      if(i+1 >= cur.size() || cur[i+1] == -1){
        nxt[i/2] = cur[i];
      } else {
        nxt[i/2] = cmp(cur[i], cur[i+1]);
      }
    }

    // cout << nxt.size() << " nxt: ";
    // for(auto x : nxt){
    //   cout << x << ' ';
    // }
    // cout << '\n';
  
    cur = nxt;
  }
  if(cur.size() == 1){
    for(int i = 0; i < n; i++){
      if(i != cur[0]){
        if(cur[0] != cmp(cur[0], i)){
          return -1;
        }
      }
    }
  }
  return cur[0]+1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cout << solve() << '\n';
  }

  return 0;
}
