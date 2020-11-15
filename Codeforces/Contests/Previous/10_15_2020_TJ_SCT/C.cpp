#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int>> grid;

int paths(<vector<vector<bool>> h, int row, int col, int c){
  h.at(row).at(col) = true;
  c++;
  if(c >= K){
    return INT_MAX;
  }
  bool left = col > 0 && !h.at(row).at(col-1);
  bool right = col < n - 1 && !h.at(row).at(col+1);
  bool up = row > 0 && !h.at(row-1).at(col);
  bool down = row < 0 && !h.at(row+1).at(col);

  vector<vector<bool>> tmp = h;

  int e = INT_MAX;
  int rec;
  if(left){
      rec = paths(h, row, col-1, c);
      e = min(e, abs(grid.at(row).at(col) - grid.at(row).at(col-1)));
      e = min(rec, e);
  }
  h = tmp;

  if(left){
      rec = paths(h, row, col-1, c);
      e = min(e, abs(grid.at(row).at(col) - grid.at(row).at(col-1)));
      e = min(rec, e);
  }
  h = tmp;

  if(left){
      rec = paths(h, row, col-1, c);
      e = min(e, abs(grid.at(row).at(col) - grid.at(row).at(col-1)));
      e = min(rec, e);
  }
  h = tmp;

  if(left){
      rec = paths(h, row, col-1, c);
      e = min(e, abs(grid.at(row).at(col) - grid.at(row).at(col-1)));
      e = min(rec, e);
  }
  h = tmp;

  return e;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for(int i = 0; i < n; i++){
    vector<int> r;
    for(int j = 0; j < n; j++){
      int x;
      cin >> x;
      r.push_back(x);
    }
    grid.push_back(r);
  }

  vector<vector<bool>> gs (n, vector(n, false));
  int m = INT_MAX;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      m = min(m, paths(gs, i, j, 0));
    }
  }

  cout << m << endl;

  return 0;
}

/*
  BRUTE FORCE
  Loop through each starting poitn
    Loop through every possible path
    Calc the min power needed
  calc min power needed
*/

/*
ANSWER
binary search through power levels:
false, false, false......true, true ture.....
flood fill on each pass to determine whether its possible or not
*/

/*
UNION FIND

*/
