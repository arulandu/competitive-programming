#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solve(){
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;

  if(b >= 0){
    return s.length()*(a+b);
  }

  vector<int> csc;
  int c = 1;
  for(int i = 1; i < s.length(); i++){
    if(s[i] == s[i-1]){
      c++;
    } else {
      csc.push_back(c);
      c = 1;
    }
  }
  csc.push_back(c);
  
  return s.length()*a+(1+csc.size()/2)*b;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t; cin >> t;
  while(t--){
    cout << solve() << '\n';
  }
  
  return 0;
}
