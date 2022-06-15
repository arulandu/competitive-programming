/*
Contest: Codeforces Round #760 (Div. 3)
Problem: [F] Reverse
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXB = 63;

// most significant bit (brute force)
ll msb(ll &x){
  for(int i = MAXB; i >= 0; i--) if(((x >> i)&1) == 1) return i;
  return -1;
}

// can x reach y by adding 1's to left (or) right of it
bool ok(ll x, ll y){
  if(x == y) return true;

  ll xmsb = msb(x);
  ll ymsb = msb(y);
  ll z = ymsb - xmsb;
  if(z <= 0) return false;
  
  int r = (x&1)==1 ? 0 : 1; // if rightmost bit is 0, at least 1 right 1 needs to be added before adding to the left
  for(; r <= z; r++){
    // add r 1's to right of and z-r 1's to left of x and check if equal
    ll rt = (1LL << r)-1LL;
    ll lf = ((1LL<<(z-r))-1LL) << (xmsb+1+r); 
    if(lf+(x << r)+rt == y) return true;
  }

  return false;
}

bool solve(){
  ll x, y; cin >> x >> y;

  ll xn0 = x; // x with trailing right zeroes cut off
  while(xn0 != 0 && !((xn0&1)==1)) xn0 = xn0 >> 1;

  // y flipped
  ll fy = 0; ll ymsb = msb(y);
  for(int i = 0; i <= ymsb; i++){
    if(((y>>i)&1) == 1){
      fy += 1<<(ymsb-i);
    }
  }

  // check if x or x cropped can reach y or y flipped (if right most of y is 1)
  return (ok(x, y) || ok(xn0, y)) || ((y&1)==1 && (ok(x, fy) || ok(xn0, fy)));

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}

/*
Erase 0s from right - only happen once
Add 1 to the right or left (1, 0)

either y or y flipped is reached by erasing 0s and adding 1

1. either keep zeroes or delete them
keep zeroes: y or y flipped has to be reachable by adding ones after the 0s
x' = x - trailing zeroes ^^
*/
