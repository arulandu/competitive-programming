#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    size_t pos;
    string tmp;
    do {
      tmp = s;
      while((pos = s.find("AB")) != string::npos){
        s.replace(pos, 2, "");
      }
    } while(tmp != s);

    do {
      tmp = s;
      while((pos = s.find("BB")) != string::npos){
        s.replace(pos, 2, "");
      }
    } while(tmp != s);

    cout << s.length() << '\n';
  }
  return 0;
}
