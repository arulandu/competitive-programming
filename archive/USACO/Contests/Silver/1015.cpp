/*
Contest: USACO 2020 February Contest Silver
Problem: #2 Triangles
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

const ll MOD = 1000000007;

struct Point {
  ll x, y;
  ll sx, sy; // sx = sum |y_i-y_j| for all j with same x val, same thing for sy
};

int main(){
  io(true, "triangles");

  int n; cin >> n;
  vector<Point> pts(n);
  for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

  // mx[k] = set of points (in ascending y order) with x coord = k
  // my[k] = set of points (in ascending x order) with y coord = k
  map<int, set<pair<int, int>>> mx, my; // .first = other coord, .second = index
  for(int i = 0; i < n; i++){
    if(!mx.count(pts[i].x)) mx[pts[i].x] = set<pair<int, int>>();
    if(!my.count(pts[i].y)) my[pts[i].y] = set<pair<int, int>>();

    mx[pts[i].x].insert({pts[i].y, i}); my[pts[i].y].insert({pts[i].x, i});
  }

  for(auto p : mx){
    // calculate prefix sum
    vector<ll> s(p.second.size()); auto it = p.second.begin();
    for(int i = 0; i < p.second.size(); i++){
      s[i] = ((i ? s[i-1] : 0)+it->first)%MOD;
      it++;
    }
    it = p.second.begin();
    for(int i = 0; i < p.second.size(); i++){
      // use sum to find sum |y_i-y_j| for all j with same x val
      pts[it->second].sx = ((s[p.second.size()-1]-s[i])-((p.second.size()-1-i)*it->first));
      if(i) pts[it->second].sx += (i*it->first) - s[i-1];
      pts[it->second].sx %= MOD;
      it++;
    }
  }

  // repeat for y direction
  for(auto p : my){
    vector<ll> s(p.second.size()); auto it = p.second.begin();
    for(int i = 0; i < p.second.size(); i++){
      s[i] = ((i ? s[i-1] : 0)+it->first)%MOD;
      it++;
    }
    it = p.second.begin();
    for(int i = 0; i < p.second.size(); i++){
      pts[it->second].sy = ((s[p.second.size()-1]-s[i])-((p.second.size()-1-i)*it->first));
      if(i) pts[it->second].sy += (i*it->first) - s[i-1];
      pts[it->second].sy %= MOD;
      it++;
    }
  }

  ll c = 0;

  // sum across all points: (sum dist of same x * sum dist of same y)
  for(auto pt : pts){
    c += (pt.sx  * pt.sy)%MOD;
    c %= MOD;
  }

  if(c < 0) c += MOD;


  cout << c << '\n';

  return 0;
}
