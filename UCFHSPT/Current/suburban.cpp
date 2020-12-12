#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define lld long long double
#define ld long double

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

bool isSquare(ll s){
  ld sr = sqrt(s);
  return (sr-floor(sr)) == 0;
}

int main(){
  handle_io(true);

  ll t;
  cin >> t;
  while(t--){
    ll rs;
    cin >> rs;
    ll mi = 1e9+1;
    for(ll x = 0; x*x <= rs/2.; x++){
      ld yd = sqrt(rs-x*x);
      ll y = floor(yd);
      if((yd-y)==0){
        // cout << x+y << ' ';
        mi = min(mi, x+y);
      }
    }
    if(mi >= 1e9+1){
      cout << -1;
    } else {
      cout << mi;
    }
    cout << '\n';

  }

  return 0;
}

/*
4
5
25
3
2
*/
