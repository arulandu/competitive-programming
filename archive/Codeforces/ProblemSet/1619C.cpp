/*
Contest: Codeforces Round #762 (Div. 3)
Problem: [C] Wrong Addition
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

string solve(){
  string a, s; cin >> a >> s;
  string o = "";

  // two pointers from right to left
  int i = a.size()-1, j = s.size()-1;
  while(j >= 0){
    int v = s[j]-'0';

    if(i < 0) { o = (char)(v+'0') + o; j--; continue; }

    // use two digits if too large
    if(a[i] > s[j]){
      j--;
      if(j < 0) return "";
      v = 10*(s[j]-'0')+s[j+1]-'0';
    }

    v -= (a[i]-'0');
    if(v > 9 || v < 0) return ""; // invalid res

    // prepend
    o = (char)(v + '0') + o;
    i--; j--;
  }

  if(i >= 0 && j < 0) return "";

  // crop leading zeroes
  int c = 0;
  while(o[c] == '0') c++;
  return o.substr(c);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) { string o = solve(); cout << (o == "" ? "-1" : o) << '\n'; }

  return 0;
}
