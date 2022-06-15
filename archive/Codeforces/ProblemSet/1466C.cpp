#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  string s; cin >> s;
  
  // mark index if end of 2-3 length palindrome 
  set<int> m;
  char l1 = ' ', l2 = ' '; // l2, l1, current
  for(int i = 0; i < s.size(); i++){
    if(s[i] == l1 && m.count(i-1) == 0){
      m.insert(i);
    } else if(s[i] == l2 && m.count(i-2) == 0){
      m.insert(i);
    }
    l2 = i > 0 ? s[i-1] : ' ';
    l1 = s[i];
  }

  cout << m.size() << '\n';
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
