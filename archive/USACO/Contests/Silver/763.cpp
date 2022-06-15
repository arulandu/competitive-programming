/*
Contest: USACO 2017 December Silver
Problem: #2 Milk Measurement
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

struct Log {
  int day;
  ll id, del;
};

int main(){
  io(true, "measurement");

  // read and sort ascending by day
  ll n, g; cin >> n >> g;
  vector<Log> logs(n);
  for(int i = 0; i < n; i++) {
    char c;
    cin >> logs[i].day >> logs[i].id >> c >> logs[i].del;
    if(c == '-') logs[i].del *= -1;
  }
  sort(logs.begin(), logs.end(), [](auto& l1, auto& l2){
    return l1.day < l2.day;
  });

  ll c = 0;

  map<ll, ll> prod; // id -> production
  map<ll, ll, greater<ll>> num; // production -> # w count
  num[0] = n+1; // "infinite" cows at 0 (let g = 0 since it doesn't matter)
  
  for(auto log : logs){
    if(!prod.count(log.id)) prod[log.id] = 0;

    // store previous wall and cow's previous production
    auto old = *num.begin();
    ll ov = prod[log.id];

    // do update
    --num[prod[log.id]];
    if(num[prod[log.id]] == 0){
      // remove nums w 0 count to prevent .begin() from finding elements
      num.erase(prod[log.id]);
    }
    prod[log.id] += log.del;
    num[prod[log.id]]++;

    // store new wall and new production
    auto nw = *num.begin();
    ll nv = prod[log.id];

    if((ov == old.first) != (nv == nw.first)){
      // cow wasn't on wall but now is or was on the wall but now isn't
      c++;
    } else if(ov == old.first && nv == nw.first){
      // if cow was on wall before and after
      // it was either the only best before and then lowered to best group or was in a best group and elevated to only best
      if(old.second > 1 || nw.second > 1) c++;
    }
  }

  cout << c << '\n';

  return 0;
}
