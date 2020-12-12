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

bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2){
  if(p1.second == p2.second){
    return p1.first > p2.first;
  } else {
    return p1.second > p2.second;
  }
}

int main(){
  handle_io(true, "rental");
  // handle_io(true);

  // read
  ll N, M, R;
  cin >> N >> M >> R;
  ll c[N];
  vector<pair<ll, ll>> m(M);
  ll tR = R < N ? N : R;
  ll r[tR];
  for(ll i = 0; i < N; i++){
    cin >> c[i];
  }
  for(int i = 0; i < M; i++){
    cin >> m[i].first >> m[i].second;
  }
  for(int i = 0; i < tR; i++){
    if(i < R){
      cin >> r[i];
    } else {
      r[i]=0;
    }
  }

  // sort
  sort(c, c+N, greater<ll>());
  sort(m.begin(), m.end(), cmp);
  sort(r, r+tR);

  // // debug
  // for(auto x : c){
  //   cout << x << ' ';
  // }
  // cout << '\n';
  // for(auto x : m){
  //   cout << '(' << x.first << ',' << x.second << ')';
  // }
  // cout << '\n';
  // for(auto x : r){
  //   cout << x << ' ';
  // }
  // cout << '\n';

  ll fp[N];
  int j = 0;
  for(int i = 0; i < N; i++){
    ll g = c[i];
    if(i == 0){
      fp[i] = 0;
    } else {
      fp[i] = fp[i-1];
    }
    while(j < M){
      ll x = min(m[j].first, g);
      g -= x;
      m[j].first -= x;
      fp[i]+=x*m[j].second;
      if(g > 0){
        j++;
      } else {
        break;
      }
    }
    // cout << fp[i] << ' ';
  }
  // cout << '\n';
  ll gp[tR];
  for(int i = 0; i < tR; i++){
    if(i == 0){
      gp[i]=0;
    } else {
      gp[i]=gp[i-1];
    }
    gp[i]+=r[i];
    // cout << gp[i] << ' ';
  }
  // cout << '\n';
  ll mx = gp[N-1];
  // cout << mx << ' ';
  for(int i = 0; i < N; i++){
    ll v = fp[i] + gp[N-1] - gp[i];
    mx = max(mx, v);
    // cout << v << ' ';
  }
  // cout << '\n';
  cout << mx;

  return 0;
}

/*
6, 2, 4, 7, 1
(10, 25), (2, 10), (15, 15)
250, 80, 100, 40

7,  6,  4,  2,   1 # desc
(10, 25), (15, 15), (2, 10), # desc cost
0  40, 80, 100, 250 # asc

f(i) is the money made by milking first i largest cows
g(j) is the money made by selling the j smallest cows
maximize f(i) + g(n-i) for i = 1...n

calc f(i) with prefix sums
calc g(j) with prefix sums
*/
