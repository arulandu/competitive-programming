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

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
  int p1d = p1.second - p1.first;
  int p2d = p2.second - p2.first;
  if(p1d==p2d){
    return (p1.first+p1.second) > (p2.first+p2.second);
  }

  return p1d > p2d;
}

int main(){
  handle_io(true, "mountains");
  // handle_io(true);
  int N;
  cin >> N;

  // read in points
  vector<pair<int, int>> pts (N);
  for(int i = 0; i < N; ++i){
    cin >> pts[i].first >> pts[i].second;
  }
  sort(pts.begin(), pts.end(), cmp);

  int maxS = 0;
  int c = 0;

  for(int i = 0; i < N; i++){
    if(maxS < pts[i].first + pts[i].second){
      c++;
      maxS = pts[i].first + pts[i].second;
    }
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
