#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

struct Point {
  ll x, y;
};

ld solve(){
  ll W, H; cin >> W >> H;
  Point b1, b2; cin >> b1.x >> b1.y >> b2.x >> b2.y;
  ll w, h; cin >> w >> h;

  ld d = LONG_LONG_MAX;

  // if translation is valid
  auto val = [&](ll dx, ll dy){
    return (dx+b2.x <= W && dx+b2.x >= 0) && (dy+b2.y <= H && dy+b2.y >= 0) && 
          (dx+b1.x <= W && dx+b1.x >= 0) && (dy+b1.y <= H && dy+b1.y >= 0);
  };

  // check each cardinal direction (picture putting additional table in corner and moving othe UDRL)

  if(val(0, h-b1.y)) d = min((ld)max(0LL, h-b1.y), d); // U
  if(val(0, -h+H-b2.y)) d = min((ld)max(0LL, h-H+b2.y), d); // D
  if(val(w-b1.x, 0)) d = min((ld)max(0LL, w-b1.x), d); // R
  if(val(-w+W-b2.x, 0)) d = min((ld)max(0LL, w-W+b2.x), d); // L
  
  return d == LONG_LONG_MAX ? -1 : d;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(numeric_limits<ld>::max_digits10);

  int t; cin >> t;
  while(t--){
    cout << solve() << '\n';
  }

  return 0;
}
