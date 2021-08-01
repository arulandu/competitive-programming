#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  string st; cin >> st;

  // generate all possible strings of size n that don't have any palindromes of size >= 2
  vector<string> pos;
  for(char i = 'a'; i < 'd'; i++){
    for(char j = 'a'; j < 'd'; j++){
      if(i == j) continue;
      string p = ""; p += i; p += j;
      for(int q = 2; q < st.size(); q++){
        // get character not present in last two ('a'-'c')
        set<char> s; s.insert(p[q-1]); s.insert(p[q-2]);
        for(int x = 'a'; x < 'd'; x++){
          if(s.count(x) == 0){
            p += x;
            break;
          }
        }
      }
      pos.push_back(p);
    }
  }

  // prefix sums for each possible string counting operations to make input string the possible string
  vector<vector<int>> pref(pos.size(), vector<int>(n));
  for(int i = 0; i < pos.size(); i++){
    for(int j = 0; j < n; j++){
      pref[i][j] = (j > 0 ? pref[i][j-1] : 0) + (pos[i][j] != st[j]);
    }
  }

  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r; l--; r--;
    if(n == 1) {
      cout << '0' << '\n';
    } else {
      // use prefix sum to calculate number of operations for each target -> minimize
      int mnc = INT_MAX;
      for(int j = 0; j < pos.size(); j++){
        int c = pref[j][r]-(l > 0 ? pref[j][l-1] : 0);
        mnc = min(c, mnc);
      }
      cout << mnc << '\n';
    }
  }

  return 0;
}
