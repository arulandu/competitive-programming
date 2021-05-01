#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

vector<vector<int>> grid (8, vector<int>(8, 0));
bool filled[8][8];

struct Pos {
  int x, y;
};

bool dfs(int x, int y){
  bool b = false;
  if(x < 0 || y < 0 || x >= 8 || y >= 8) b = false;
  if(filled[x][y]) b = false;
  if(grid[x][y] < 0) return false;

  filled[x][y] = true;
  if(grid[x][y] == 2) return true;

  return dfs(x-1, y-1)|| dfs(x-1, y+1) || dfs(x+1, y-1) || dfs(x+1, y+1);
}

void readBound(){
  char c;
  for(int i = 0; i < 17; i++){
    cin >> c;
  }
}

void solve(){
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      filled[i][j] = false;

  char uc;
  readBound();

  vector<Pos> bish;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j <= 8; j++){
      char c;
      cin >> c;
      if(isalpha(c)){
        j--;
        grid[i][j] = islower(c) ? 1 : -1;
        if(tolower(c) == 'k') grid[i][j] *= 2;
        if(c == 'B'){
          bish.push_back({i, j});
        }
      }
    }
    readBound();
  }

  for(auto b : bish){
    if(dfs(b.x, b.y)){
      cout << "CAPTURED\n";
      return;
    }
  }

  cout << "SAFE\n"; 
}

int main(){
  cin.tie(0); ios_base::sync_with_stdio(false);
  int n;cin >> n;
  while(n--){
    solve();
  }

  return 0;
}

/*
2
-----------------
|P| | | |R| | |k|
-----------------
|B| | | |Q| | | |
-----------------
|P|N|P| | | | | |
-----------------
| | | | | | | | |
-----------------
| | |K| | | | |P|
-----------------
| | | | | | | |n|
-----------------
| | | |R| | | |b|
-----------------
| | | | | |b| | |
-----------------
-----------------
| | |r| | |p| | |
-----------------
|P| | |p|P| | |P|
-----------------
|P| | |b| | |R| |
-----------------
| | | |N| | | | |
-----------------
| | | | | | |p| |
-----------------
| | |K|p| |N|P| |
-----------------
| | |P|k|p|p| | |
-----------------
| |B| | |p| | | |
-----------------
*/