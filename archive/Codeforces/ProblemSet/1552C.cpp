#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;

  vector<pair<int, int>> ch;
  vector<bool> vis (2*n+1, false);
  for(int i = 0; i < k; i++){
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    vis[a] = vis[b] = true;
    ch.push_back({a, b});
  }
  vector<int> open;
  for(int i = 1; i <= 2*n; i++){
    if(!vis[i]) open.push_back(i);
  }

  for(int i = 0; i < n-k; i++){
    ch.push_back({open[i], open[i+n-k]});
  }

  auto itx = [&](int i, int j){
    return (ch[i].first < ch[j].first && ch[i].second < ch[j].second && ch[i].second > ch[j].first)
    || (ch[i].first > ch[j].first && ch[i].second > ch[j].second && ch[i].first < ch[j].second);
  };
  
  int c = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(itx(i, j)) c++;
    }
  }

  cout << c << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    // cout << "t: " << t << '\n';
    solve();
  }

  return 0;
}
