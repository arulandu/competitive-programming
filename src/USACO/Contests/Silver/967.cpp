/*
Contest: USACO 2019 December Silver
Problem: #2 Meetings
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

int main(){
  io(true, "meetings");

  int n, l; cin >> n >> l;
  vector<pair<int, pair<int, int>>> cows(n); // weight, x, d
  for(int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second.first >> cows[i].second.second;
  sort(cows.begin(), cows.end(), [](auto &c1, auto &c2){
    return c1.second.first < c2.second.first;
  });

  // get ending times
  // the ending times of the z left-most cows is the x-vals of the left-heading cows[i]
  vector<pair<int, int>> times; // time, weight
  for(int i = 0; i < cows.size(); i++){
    if(cows[i].second.second == -1){
      times.push_back({cows[i].second.first, cows[times.size()].first});
    }
  }

  // the ending times of the z right-most cows is the length minus x-vals of the right-heading cows[i]
  int z = times.size(); // # goin left
  for(int i = 0; i < cows.size(); i++){
    if(cows[i].second.second == 1)
      times.push_back({l-cows[i].second.first, cows[z++].first});
  }

  sort(times.begin(), times.end(), [](auto& t1, auto& t2){
    return t1.first < t2.first;
  });

  // get time where sum of weights is >= half*tot
  int tot = 0; for(auto& t : times) tot += t.second;
  int time = 0;
  for(auto& t : times){
    tot -= 2*t.second;
    if(tot <= 0) {
      time = t.first;
      break;
    }
  }

  // meetings: find two cows facing opposite directions within 2*T distance
  int mts = 0;

  queue<int> right; // cow xs going right
  for(int i = 0; i < n; i++){
    if(cows[i].second.second == -1){
      // if right.front() can't hit cows[i] in time, it won't hit cows after cows[i] in time
      while(!right.empty() && right.front()+2*time < cows[i].second.first){
        right.pop();
      }
      
      mts += right.size(); // cows[i] going left hits all cows going right that are within 2T away
    } else {
      right.push(cows[i].second.first);
    }
  }

  cout << mts << '\n';
  return 0;
}
