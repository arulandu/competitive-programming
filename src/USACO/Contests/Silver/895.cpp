/*
Contest: USACO 2019 January Silver
Problem: #2 Icy Perimeter
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

const int MAXN = 1000;
bool grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n;

// flood fill | (area, perimeter)
pair<int, int> fill(int r, int c){
  int area = 0, per = 0;
  stack<pair<int, int>> fringe;

  fringe.push({r, c});
  while(!fringe.empty()){
    auto v = fringe.top(); fringe.pop();
    if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= n || !grid[v.first][v.second]){
      per++;
      continue;
    }

    // previously visited # cells don't contribute to perimeter
    if(vis[v.first][v.second]) continue;

    // all # cells contribute 1 area
    vis[v.first][v.second] = true;
    area++;

    fringe.push({v.first +1, v.second });
    fringe.push({v.first -1, v.second });
    fringe.push({v.first, v.second -1});
    fringe.push({v.first, v.second +1});
  }
  
  return {area, per};
}

int main(){
  io(true, "perimeter");

  cin >> n;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++){
      grid[i][j] = s[j] == '#';
      vis[i][j] = false;
    }
  }

  int area = 0; int per = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      // flood fill components and max area then min perim
      if(!vis[i][j] && grid[i][j]){
        pair<int, int> r = fill(i, j);

        if(r.first > area){
          area = r.first; per = r.second;
        } else if(r.first == area) {
          per = min(r.second, per);
        }
      }
    }
  }

  cout << area << ' ' << per << '\n';

  return 0;
}
