#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Event {
  bool a;
  ll t;
  int i;
};

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  // read events, sort by time then prioritize arrivals over departures
  int n; cin >> n;
  vector<Event> ets(2*n); for(int i = 0; i < n; i++){ 
    ll a, b; cin >> a >> b; ets[2*i] = {true, a, i}; ets[2*i+1] = {false, b, i};
  }
  sort(ets.begin(), ets.end(), [](auto& e1, auto& e2){
    return e1.t == e2.t ? (e1.a == e2.a ? e1.i < e2.i : e1.a > e2.a) : e1.t < e2.t;
  });

  // simulate open room set and calculate mapping
  set<int> op; map<int, int> rm; int r = 0;
  for(auto& e : ets){
    if(e.a) {
      if(op.size() < 1) {
        r++; op.insert(r);
      }

      rm[e.i] = *op.begin(); op.erase(rm[e.i]);
    } else {
      op.insert(rm[e.i]);
    }
  }
  
  // output
  cout << r << '\n';
  for(auto p : rm) cout << p.second << ' ';
  cout << '\n';

  return 0;
}
