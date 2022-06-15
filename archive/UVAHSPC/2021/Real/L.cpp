#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int m;
  cin >> m;

  vector<int> v(m);
  for(int i = 0; i < m; i++){
    cin >> v[i];
  }

  int s = 0;
  sort(v.begin(), v.end(), greater<>());
  for(int i = 0; i < (v.size()+1)/2; i++){
    s += v[i];
  }

  cout << s << '\n';
}

int main(){
  cin.tie(0);ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while(n--){
    solve();
  }

  return 0;
}

/*
2
5
3 80 14 40 99
11
59 90 9 76 58 21 87 87 54 47 59

*/
