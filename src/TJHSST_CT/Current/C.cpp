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

bool cmp1(const pair<int, ll> &p1, const pair<int, ll> &p2){
  return p1.second < p2.second;
}

bool cmp2(const pair<int, ll> &p1, const pair<int, ll> &p2){
  return p1.first < p2.first;
}

int main(){
  handle_io(true);

  int n, q;
  cin >> n >> q;
  vector<pair<int, ll>> ar (2*n);
  for(int i = 0; i < n; i++){
    ll x;
    cin >> x;
    ll l = x + 1;
    ll r = (x*(x+1)/2) + 1;
    ar[2*i] = make_pair(1, l);
    ar[2*i+1] = make_pair(-1, l);
  }

  for(int i = 0; i < q; i++){
    ll p;
    cin >> p;
    auto low = lower_bound(ar.begin(), ar.end(), make_pair(-1, p), cmp1);
    auto high = upper_bound(ar.begin(), ar.end(), make_pair(p, 1), cmp2);
    ll diff = high - low;
    cout << diff << '\n';
  }



  return 0;
}
