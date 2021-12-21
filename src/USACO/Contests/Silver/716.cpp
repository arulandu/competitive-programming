/*
Contest: USACO 2017 February Silver
Problem: #3 Why Did The Cow Cross The Road III
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

const int MAXN = 100;
int grid[MAXN][MAXN];
int n, k, r;
set<pair<pair<int, int>, pair<int, int>>> rds;
const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};

// color component (without using roads)
void fill(int r, int c, int col){
  stack<pair<int, int>> fringe;
  fringe.push({r, c});

  while(!fringe.empty()){
    auto v = fringe.top(); fringe.pop();
    if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= n || grid[v.first][v.second] != -1) continue;

    grid[v.first][v.second] = col;
    
    for(int i = 0; i < 4; i++){
      pair<int, int> p = {v.first+dr[i], v.second+dc[i]};
      if(!rds.count({v, p}) && !rds.count({p, v}))
        fringe.push(p);
    }
  }
}

int main(){
  io(true, "countcross");

  // read data (convert coords to [0,n))
  cin >> n >> k >> r;
  for(int i = 0; i < r; i++){
    pair<int, int> f, fp; cin >> f.first >> f.second >> fp.first >> fp.second;
    rds.insert({{f.first-1, f.second-1}, {fp.first-1, fp.second-1}});
  }

  vector<pair<int, int>> cows(k);
  for(int i = 0; i < k; i++) {
    cin >> cows[i].first >> cows[i].second;
    cows[i].first--; cows[i].second--;
  }

  // fill grid w -1s
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      grid[i][j] = -1;

  // color components
  int c = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == -1){
        fill(i, j, ++c);
      }
    }
  }

  // count # cows in each component
  map<int, int> comps;
  for(auto& cw : cows){
    int col = grid[cw.first][cw.second];
    if(!comps.count(col)) comps[col] = 0;
    comps[col]++;
  }

  // multiply # cows in diff components to count distant
  int d = 0;
  for(auto& c1 : comps){
    for(auto& c2 : comps){
      if(c1.first < c2.first) d += c1.second*c2.second;
    }
  }

  cout << d << '\n';

  return 0;
}
