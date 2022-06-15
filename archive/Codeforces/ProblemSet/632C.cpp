/*
Contest: Educational Codeforces Round 9
Problem: C The Smallest String Concatenation
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<string> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end(), [](auto &s1, auto &s2){
    // check which concatenation order is smaller
    return s1+s2 < s2+s1;
  });

  // concat
  string s = "";
  for(auto t : v) s += t;
  cout << s << '\n';
  return 0;
}