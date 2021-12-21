#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double
const ld EPSILON = 1e-8;

struct Point {
  ld x, y;

  bool operator==(Point &p){
    return p.x == x && p.y == y;
  }

  Point operator+(Point &p){
    return {p.x+x, p.y+y};
  }
  
  Point operator-(Point &p){
    return {x-p.x, y-p.y};
  }

  Point operator/(ld s){
    return {x/s, y/s};
  }

  ld dist(Point &p){
    return sqrtl(powl(x-p.x, 2.) + powl(y-p.y, 2.));
  }
};

ld calc_tri_per(Point &a, Point &b, Point &c){
  return a.dist(b)+b.dist(c)+c.dist(a);
}

bool pt_inside_tri(Point &p, Point &a, Point &b, Point &c){
  return true;
}

bool pt_on_tri(Point &p, Point &a, Point &b, Point &c){
  return pt_on_seg(p, a, b) || pt_on_seg(p, a, c) || pt_on_seg(p, b, c);
}

bool pt_on_seg(Point &p, Point &a, Point &b){
  if(abs(a.x - b.x) < EPSILON){ //vert
    return abs(p.x-a.x) < EPSILON;
  }
  if(abs(a.y - b.y) < EPSILON){ //horz
    return abs(p.y - a.y) < EPSILON;
  }

  return abs(p.dist(a) + p.dist(b) - a.dist(b)) < EPSILON;
}

bool pt_inside_quad(Point &p, Point &a, Point &b, Point &c, Point &d){
  return true;
}

ld calc_quad_per(Point &a, Point &b, Point &c, Point &d){
  return 1.0;
}

void solve(){
  int n; cin >> n;
  vector<Point> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].x >> v[i].y;
  }

  Point bs; cin >> bs.x >> bs.y;

  ld per = LDBL_MAX;
  for(auto a : v){
    for(auto b : v){
      if(b == a) continue;
      for(auto c : v){
        if(b == c || a == c) continue;

        if(pt_inside_tri(bs, a, b, c)){
          per = min(per, calc_tri_per(a, b, c));
        }

        for(auto d : v){
          if(b == d || a == d || c == d) continue;

          if(pt_inside_quad(bs, a, b, c, d)){
            per = min(per, calc_quad_per(a, b, c, d));
          }
        }
      }
    }
  }

  if(abs(per-LDBL_MAX) < EPSILON){
    cout << "IMPOSSIBLE";
  } else {
    cout << per;
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout.precision(numeric_limits<ld>::max_digits10);

  int t;
  cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
    cout << "\n";
  }

  return 0;
}
