#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int m;
  cin >> m;

  map<int, int> mp;
  for(int i = 0; i < m; i++){
    int s, e; string u;
    cin >> s >> u >> e;
    mp.insert(make_pair(s, e));
  }

  int k;
  cin >> k;

  int c = 0;
  vector<int> v(k);
  for(int i = 0; i < k; i++){
    cin >> v[i];
  }
  for(int i = 0; i < k; i++){
    c += v[i];

    if(c >= 99){
      cout << i+1 << '\n';
      return;
    }

    while(mp.find(c) != mp.end()){
      c = mp[c];
    }

    if(c >= 99){
      cout << i+1 << '\n';
      return;
    }
  }

  cout << "Still playing!\n";
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while(n--){
    solve();
  }

  return 0;
}

/*
2
2
10 =ladder=> 97
98 =chute=> 2
4
4 6 1 1
6
1 =ladder=> 99
2 =ladder=> 99
3 =ladder=> 99
4 =ladder=> 99
5 =ladder=> 99
6 =ladder=> 99
4
1 2 3 4

*/
