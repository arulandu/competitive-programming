#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  string s2 = s;
  sort(s2.begin(), s2.end());
  int k = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] != s2[i]) k++;
  }

  cout << k << '\n';
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
