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

int main(){
  handle_io(true);

  int n; cin >> n;
  vector<pair<int, int>> pts(n);
  for(int i = 0; i < n; i++){
    cin >> pts[i].first >> pts[i].second;
  }
  vector<pair<int, int>> ptsX = pts;
  vector<pair<int, int>> ptsY = pts;
  sort(ptsX.begin(), ptsX.end(), [](auto const &p1, auto const &p2){
    return p1.first < p2.first;
  });
  sort(ptsY.begin(), ptsY.end(), [](auto const &p1, auto const &p2){
    return p1.second < p2.second;
  });

  cout << "X: ";
  for(auto x : ptsX){
    cout << x.first << ' ' << x.second << ", ";
  }
  cout << "\nY: ";
  for(auto y : ptsY){
    cout << y.first << ' ' << y.second << ", ";
  }
  cout << '\n';


  int a = 0;
  for(int i = 1; i < n; i++){
    if(ptsX[i].first != ptsX[i-1].first) continue;
    int h = abs(ptsX[i].second - ptsX[i-1].second);
    cout << h << ' ';
    auto lb = lower_bound(ptsY.begin(), ptsY.end(), ptsX[i], [](auto const &p1, auto const &p2){
      return p1.second < p2.second;
    });
    cout << '(' << lb-> first << ',' << lb-> second << ')';
    while(lb->second == ptsX[i].second){
      a += h*abs(lb->first - ptsX[i].first);
      lb++;
    }

    lb = lower_bound(ptsY.begin(), ptsY.end(), ptsX[i-1], [](auto const &p1, auto const &p2){
      return p1.second < p2.second;
    });
    cout << '(' << lb-> first << ',' << lb-> second << ')';
    while(lb->second == ptsX[i].second){
      a += h*abs(lb->first - ptsX[i].first);
      lb++;
    }
  }

  cout << a << '\n';

  return 0;
}
