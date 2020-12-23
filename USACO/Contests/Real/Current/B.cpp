#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll MAX = 1e9 + 1;

struct Box {
  ll x, y, w, h;

  void display(){
    cout << "(" << x << ", " << y << ", " << w << ", " << h << ")" << '\n';
  }
};

struct BoxCompare {
  bool operator()(const Box& b1, const Box& b2) const {
    if(b1.x != b2.x){
      return b1.x < b2.x;
    } else if(b1.y != b2.y){
      return b1.y < b2.y;
    } else if(b1.w != b2.w){
      return b1.w < b2.w;
    } else {
      return b1.h < b2.h;
    }

  }
};

struct Point {
  ll x, y;
};

bool cmp1(const Point &p1, const Point &p2){
  return p1.x < p2.x;
}

bool cmp2(const Point &p1, const Point &p2){
  return p1.y < p2.y;
}

int main(){
  int N;
  cin >> N;
  vector<Point> pts (N), ptsX, ptsY;
  set<Box, BoxCompare> bs;

  for(int i = 0; i < N; i++){
    cin >> pts[i].x >> pts[i].y;
  }
  ptsX = pts;
  ptsY = pts;
  sort(ptsX.begin(), ptsX.end(), cmp1); // O(nlogn)
  sort(ptsY.begin(), ptsY.end(), cmp2); // O(nlogn)

  // O(n^2 / 2)
  for(int i = 0; i < N; i++){
    ll miny = ptsX[i].y;
    ll maxy = miny;
    for(int s = 1; s <= N-i; s++){
      int j = i + s-1;
      miny = min(ptsX[j].y, miny);
      maxy = max(ptsX[j].y, maxy);
      Box bx = {ptsX[i].x, miny, ptsX[j].x-ptsX[i].x, maxy-miny};
      bs.insert(bx);
      // cout << "YES: ";
      // bx.display();
    }
  }

  // cout << bs.size() << '\n';

  // O(n^2 / 2)
  for(int i = 0; i < N; i++){
    ll minx = ptsY[i].x;
    ll maxx = minx;
    for(int s = 1; s <= N-i; s++){
      int j = i + s-1;
      minx = min(ptsY[j].x, minx);
      maxx = max(ptsY[j].x, maxx);
      Box bx = {minx, ptsY[i].y, maxx-minx, ptsY[j].y-ptsY[i].y};
      bs.insert(bx);
      // cout << "YES: ";
      // bx.display();
    }
  }

  cout << bs.size()+1 << '\n'; // TOTAL: Time: O(n^2), Space: N^2


  return 0;
}

/*
4
0 2
1 0
2 3
3 5
*/
