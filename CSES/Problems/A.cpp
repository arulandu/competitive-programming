#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
  return p1.first < p2.first;
}

int main(){
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++){
    pair<int, int> start;
    pair<int, int> end;
    cin >> start.first >> end.first;
    start.second = 1;
    end.second = -1;
    v.push_back(start);
    v.push_back(end);
  }

  sort(v.begin(), v.end(), cmp);

  int best = 0;
  int sum = 0;
  for(int k = 0; k < n*2; k++){
      sum = max(v[k].second, sum+v[k].second);
      best = max(best, sum);
  }

  cout << best << '\n';

  return 0;
}
