#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

struct Event {
  ll i, h, d;
  bool end;
};

void solve(){
  // cout << "\n";

  ll d, n, k; cin >> d >> n >> k;
  
  vector<Event> v(2*n);
  for(ll i = 0; i < n; i++){
    ll h, s, e; cin >> h >> s >> e;
    v[2*i] = {i: i, h: h, d: s, end: false};
    v[2*i+1] = {i: i, h: h, d: e, end: true};
  }

  // O(2n*Log[2n])
  sort(v.begin(), v.end(), [](const Event &e1, const Event &e2){
    if(e1.d == e2.d){
      if(e1.end == e2.end) return false;
      return !e1.end;
    } else {
      return e1.d < e2.d;
    }
  });

  auto hcmp = [](const Event &e1, const Event &e2){
    if(e1.h == e2.h){
      if(e1.end == e2.end) return false;
      return !e1.end;
    } else {
      return e1.h < e2.h;
    }
  };
  priority_queue<Event, vector<Event>, decltype(hcmp)> pq(hcmp);
  
  ll mx = LONG_LONG_MIN;

  stack<Event> st;
  auto calc = [&k, &pq, &st, &mx](){
    // calculate rating
    ll c = 0;
    for(ll i = 0; i < k && !pq.empty();){
      Event pe = pq.top();
      pq.pop(); st.push(pe);
      if(!pe.end){
        // cout << "attending: i: " << pe.i << " d: " << pe.d << " h: " << pe.h << '\n'; 
        c += pe.h;
        i++;
      }
    }

    mx = max(mx, c);
    // cout << "calculated c: " << c << " mx: " << mx << '\n';

    // restore
    while(!st.empty()){
      pq.push(st.top()); st.pop();
    }
  };

  for(auto e : v){
    // cout << " i: " << e.i << " d: " << e.d << " h: " << e.h << " end: " << (e.end ? 'y' : 'n') << '\n';
    if(!e.end) {
      pq.push(e); 
      // cout << " pushing\n";
    }
    calc();

    if(e.end) {
      // remove corresponding start element
      // cout << "removing: " << "size: " << pq.size() << ' ';
      while(!pq.empty()){
        Event pe = pq.top(); pq.pop(); 
        if(!pe.end && pe.i == e.i){
          break;
        } else {
          st.push(pe);
        }
      }

      while(!st.empty()){
        pq.push(st.top()); st.pop();
      }
      // cout << "-> " << pq.size() << '\n';
    }
  }

  cout << mx;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
    cout << "\n";
  }

  return 0;
}
