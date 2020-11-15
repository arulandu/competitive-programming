#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  stack<pair<ll, ll>> s;
  for(ll i = 0; i < n; i++){
    pair<ll, ll> r;
    cin >> r.first >> r.second;
    // cout << r.first << r.second;
    // cout << "d\n";
    if(s.empty()){
      s.push(r);
    } else {
      pair<ll, ll> &t = s.top();
      if(t.second == 1 && r.second == 0){
        // collide
        if(t.first > r.first){
          t.first -= r.first;
        } else if(t.first == r.first) {
          s.pop();
        } else {
          r.first -= t.first;
          s.pop();
          s.push(r);
        }
      } else {
        s.push(r);
      }
    }
    // cout << "d\n";
  }

  cout << s.size() << '\n';
  // reverse order
  stack<pair<ll, ll>> temp;
  while(!s.empty()){
    temp.push(s.top());
    s.pop();
  }

  while(!temp.empty()){
    pair<ll, ll> &r = temp.top();
    temp.pop();
    cout << r.first << ' ' << r.second << '\n';
  }

  return 0;
}
