#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    string s; cin >> s;
    cout << "Case #" << i << ": " << s << " is ruled by ";
    if(s[s.size()-1] == 'y' || s[s.size()-1] == 'Y'){
      cout << "nobody";
    } else {
      set<char> vws = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      cout << (vws.count(s[s.size()-1]) == 1? "Alice" : "Bob");
    }

    cout << ".\n";
  }

  return 0;
}
