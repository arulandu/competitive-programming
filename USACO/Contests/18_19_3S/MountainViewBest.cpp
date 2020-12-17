#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

struct Point {
  int x, y;
  int yScore;
  int diffScore;
  int sumScore;
};

bool isInside(const Point &p1, const Point &p2){
  //returns true if p2 is inside p1
  return
    p2.y <= p1.y &&
    (p2.y - p1.y + p1.x <= p2.x) &&
    (p2.x <= p1.x + p1.y - p2.y);
}

bool cmp1(const Point &p1, const Point &p2){
  return p1.y > p2.y;
}

bool cmp2(const Point &p1, const Point &p2){
  return (p1.y-p1.x) > (p2.y-p2.x);
}

bool cmp3(const Point &p1, const Point &p2){
  return (p1.y+p1.x) > (p2.y+p2.x);
}

int main(){
  handle_io(true, "mountains");
  // handle_io(true);
  int N;
  cin >> N;

  // read in points
  vector<Point> pts (N), ptsY (N), ptsDiff (N);
  for(int i = 0; i < N; ++i){
    cin >> pts[i].x >> pts[i].y;
    pts[i].yScore = -1;
    pts[i].sumScore = -1;
    pts[i].diffScore = -1;
  }

  sort(pts.begin(), pts.end(), cmp1); // sort desc in y and update index "score"
  for(int i = 0; i < N; i++){
    pts[i].yScore = i;
  }
  ptsY = pts; // save this sorting
  sort(pts.begin(), pts.end(), cmp2); // sort desc in y-x, update index "score"
  for(int i = 0; i < N; i++){
    pts[i].diffScore = i;
  }
  ptsDiff = pts; // save this sorting
  sort(pts.begin(), pts.end(), cmp3); // sort desc in x+y, update index "score"
  for(int i = 0; i < N; i++){
    pts[i].sumScore = i;
  }

  int c = 0;
  for(int i = 0; i < N; i++){
    int q = min(min(pts[i].yScore, pts[i].sumScore), pts[i].diffScore); // find minimum of all scores

    // search previous elements in corresponding array
    if(q == pts[i].yScore){
      for(int j = 0; j < q; j++){
        if(isInside(ptsY[j], pts[i])){
          goto skip;
        }
      }
    } else if(q == pts[i].diffScore){
      for(int j = 0; j < q; j++){
        if(isInside(ptsDiff[j], pts[i])){
          goto skip;
        }
      }
    } else if(q == pts[i].sumScore){
      for(int j = 0; j < q; j++){
        if(isInside(pts[j], pts[i])){
          goto skip;
        }
      }
    }
    c++;
    skip:;
  }

  cout << c << '\n';

  return 0;
}

/*
Discovered (in not optimal solution):
  mountain j covers i if
    - y_i <= y_j AND
    - y_i - x_i <= y_j - x_j AND
    - x_i + y_i <= x_j + y_j

Discovery 2:
  - the condition y_i <= y_j can be neglected as for y_i > y_j, the following conditions won't hold

With this, an O(nlogn) solution can be used by first sorting to staisfy one constraint
and using a variable to keep track of the other.

PLAN:
  - read input into vector
  - sort vector by y-x increasing and then x+y decreasing if differences are equal
  - loop through and calculate the maximum x+y
  - use this max to determine if a mountain is obscured when max(x+y) >= x_a + y_a
  - if not obscured increment counter

The actaul looping here is O(n) and the 1 sort takes O(nlogn). This makes the whole
method O(nlogn) much more optimal than the method shown in "MountainViewNotOptimal.cpp".


*/
