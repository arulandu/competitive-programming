#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  map<string, string> m;
  for(int i = 0; i < n; i++){
    string s1, s2; cin >> s1 >> s2;
    m[s1] = s2;
  }

  for(int i = 0; i < q; i++){
    string s; cin >> s;
    if(m.count(s) > 0){
      cout << m[s] << '\n';
    } else {
      cout << "Not Found" << '\n';
    }
  }

  return 0;
}
