#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    if(s.size() <= 10){
      cout << s << '\n';
    } else {
      cout << s[0] << (s.size()-2) << s[s.size()-1] << '\n';
    }
  }

  
  return 0;
}
