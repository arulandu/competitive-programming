/*
Contest: USACO 2018 December Silver
Problem: #2 Convention II
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

struct Cow {
  int s, t;
  ll a;
};

int main(){
  io(true, "convention2");

  // read in cows, sort increasing by arrival time, and move into stack with earliest arrivals on top
  int n; cin >> n;
  vector<Cow> cows(n);
  for(int i = 0; i < n; i++){
    cin >> cows[i].a >> cows[i].t; cows[i].s = i;
  }
  sort(cows.begin(), cows.end(), [](auto& c1, auto& c2){
    return c1.a < c2.a;
  });
  stack<Cow> st; for(int i = cows.size()-1; i>=0; i--){st.push(cows[i]);};
  
  // waiting queue with prioritizing seniority (lower order - s)
  auto bySen = [](Cow& c1, Cow& c2){return c1.s > c2.s;};
  priority_queue<Cow, vector<Cow>, decltype(bySen)> line(bySen);
  
  // simulate
  ll t = 0; ll md = INT_MIN;
  while(!st.empty()){
    // add new arrivals to waiting queu
    while(!st.empty() && st.top().a <= t){
      auto c = st.top(); st.pop();
      line.push(c);
    }

    Cow c;
    if(!line.empty()){
      // get next cow in queue and max delay
      c = line.top(); line.pop();
      md = max(t-c.a, md);
    } else {
      // no queue, so wait till next cow arrival in stack (0 delay)
      c = st.top(); st.pop();
      t = c.a;
      md = max(0LL, md);
    }

    t += c.t; // wait for cow to finish
  }

  cout << md << '\n';

  return 0;
}
