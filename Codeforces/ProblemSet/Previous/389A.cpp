#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  map<string, int> m;

  for(int i = 0; i < 10; i++){
    string v;
    cin >> v;
    m[v] = i;
  }
  map<string, int>::iterator itr;

  for(int i = 0; i < 10; i++){
    string x = s.substr(i*8, 8);
    cout << "x: " << x << endl;
    itr = m.find(x);
    cout << (itr->second);
  }
  cout << endl;

  return 0;
}
