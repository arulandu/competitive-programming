#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;

  vector<pair<int, int>> ch (k);
  vector<bool> vis (2*n+1);
  for(int i = 0; i < k; i++){
    cin >> ch[i].first >> ch[i].second;
    if(ch[i].first > ch[i].second) swap(ch[i].first, ch[i].second);
    vis[ch[i].first] = vis[ch[i].second] = true;
  }
  int p = -1;
  for(int i = 1; i <= 2*n; i++){
    if(!vis[i]) {
      if(p == -1){
        p = i;
        continue;
      }
      ch.push_back({p, i});
      vis[p] = vis[i] = true;
      p = -1;
    }
  }

  for(int i = 0; i < n; i++){
    cout << i << ' ' << ch[i].first << ' ' << ch[i].second << '\n';
  }
  cout << '\n';

  auto itx = [&](int i, int j){
    return (ch[i].first < ch[j].first && ch[i].second < ch[j].second && ch[i].second > ch[j].first)
    || (ch[i].first > ch[j].first && ch[i].second > ch[j].second && ch[i].first < ch[j].second);
  };

  for(int i = k; i < n; i++){
    for(int j = i+1; j < n; j++){
      cout << i << ' ' << j << '\n';
      // swap if no intersect
      if(!itx(i, j)){
        swap(ch[j].first > ch[i].second ? ch[j].first : ch[j].second, ch[i].second);
      }
    }
  }

  for(int i = 0; i < n; i++){
    cout << i << ' ' << ch[i].first << ' ' << ch[i].second << '\n';
  }
  cout << '\n';

  int c = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(itx(i, j)){
        c++;
      }
    }
  }

  cout << c << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cout << "t: " << t << '\n';
    solve();
  }

  return 0;
}
