/*
Contest: Educational Codeforces Round 46
Problem: [C] Covered Points Count
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  // read input, sort delta events ascending in time, place in stack (top is earliest event)
  int n; cin >> n;
  vector<pair<ll, bool>> ev(2*n); // events
  for(int i = 0; i < n; i++){
    ll l, r; cin >> l >> r;
    ev[2*i] = {l, true}; ev[2*i+1] = {r+1, false};
  }
  sort(ev.begin(), ev.end());
  stack<pair<ll, bool>> st; for(int i = 2*n-1; i >= 0; i--) st.push(ev[i]);

  // process events keeping a running total and counting
  map<int, ll> ans; // count -> # pts
  ll tot = 0; ll prev = -1;
  while(!st.empty()){
    // count previous total
    auto e = st.top();
    ans[tot] += e.first-prev; prev = e.first;

    // apply net delta at time
    ll del = 0;
    while(!st.empty() && st.top().first == e.first){
      del += st.top().second ? 1 : -1; st.pop();
    }
    tot += del;
  }

  // log
  for(int i = 1; i <= n; i++) cout << (ans.count(i) ? ans[i] : 0) << (i < n ? ' ' : '\n');

  return 0;
}
