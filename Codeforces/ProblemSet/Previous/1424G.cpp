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

bool cmp(pair<ll, ll> &p1, pair<ll, ll> &p2){
  if(p1.first == p2.first){
    return p1.second < p2.second;
  } else {
    return p1.first < p2.first;
  }
}

int main(){
  handle_io(true);

  ll n;
  cin >> n;
  vector<pair<ll, ll>> v;
  for(int i = 0; i < n; i++){
    pair<ll, ll> p1;
    pair<ll, ll> p2;
    cin >> p1.first >> p2.first;
    p1.second = 1;
    p2.second = -1;
    v.push_back(p1);
    v.push_back(p2);
  }

  sort(v.begin(), v.end(), cmp);

  ll best = 0;
  ll bi = 0;
  ll sum = 0;
  for(ll i = 0; i < 2*n; i++){
    sum = max(v[i].second, v[i].second+sum);
    if(sum > best){
      best = sum;
      bi = i;
    }
  }
  cout << v[bi].first << ' ' << best << '\n';

  return 0;
}
