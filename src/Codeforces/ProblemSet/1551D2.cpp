#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void solve(){
  int n, m, k; cin >> n >> m >> k;

  // check validity
  bool b; 
  if(k < 0 || k > (n*m)/2)
    b = false;
  if(n % 2 == 0){
    b = k%2==0 && k <= n*(m/2);
  } else {
    b = k >= m/2 && (k-m/2)%2 == 0;
  }
  if(!b){
    skip:;
    cout << "NO\n"; return;
  }

  // create grid
  vector<vector<char>> ar(n, vector<char>(m, ' '));
  char c = 'a';

  auto getC = [&](int i, int j) {
    // get char if exists
    if(i < 0 || i >= n || j < 0 || j >= m){
      return ' ';
    } else {
      return ar[i][j];
    }
  };

  auto nxtC = [&](int i, int j) {
    // insert boundary chars
    set<char> s;
    s.insert(getC(i-1, j)); s.insert(getC(i-1, j+1)); s.insert(getC(i, j+2));
    s.insert(getC(i, j-1)); s.insert(getC(i+1, j-1)); s.insert(getC(i+2, j));
    s.insert(getC(i+1, j+1));

    // get first non-boundary
    for(char ci = 'a'; ci <= 'z'; ci++){
      if(s.count(ci) == 0){
        c = ci;
        return;
      }
    }
    c = '-';
  };

  // fill top line
  if(n%2 == 1){
    for(int j = 0; j < m; j+=2){
      nxtC(0, j);
      ar[0][j] = c; ar[0][j+1] = c;
      k--;
    }
  }

  // fill grid
  int di = 1, dj = 2;
  for(int j = 0; j < m; j+=dj){
    bool flg = false;
    for(int i = n%2; i < n; i+=di){
      if(k == 0){
        if(flg){
          // fill vertical (2) under horizontal
          nxtC(i, j);
          ar[i][j] = c; ar[i+1][j] = c;
          nxtC(i, j+1);
          ar[i][j+1] = c; ar[i+1][j+1] = c;
          di = 2;
        } else {
          // fill vertical (1)
          nxtC(i, j);
          ar[i][j] = c; ar[i+1][j]= c;
          dj = 1; di = 2;
        }
      } else {
        // fill horizontal
        nxtC(i, j);
        ar[i][j] = c;
        ar[i][j+1] = c;
        k--; if(k <= 0) flg = true;
      }
    }
  }

  // print grid
  cout << "YES\n";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << ar[i][j];
    }
    cout << '\n';
  }
  return;
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
