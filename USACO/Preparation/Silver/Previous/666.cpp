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

int main(){
  handle_io(true, "haybales");

  int n, q;
  cin >> n >> q;

  vector<ll> v;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  for(int i = 0; i < q; i++){
    ll a, b;
    cin >> a >> b;
    cout << (upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a)) << '\n';
  }

  return 0;
}
