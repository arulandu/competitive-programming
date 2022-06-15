/*
Contest: Codeforces Round #767 (Div. 2)
Problem: [E] Grid Xor
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
int gd[1000][1000];

int calc(int of){
  int res = 0;
  
  auto add = [&res, &of](int r, int c){
    res ^= gd[r+of][c+of];
  };

  int sn = n-2*of; // size of current inner square
  bool i4 = sn % 4 == 0; // parity

  // hard code n=2, n=4 patterns
  if(sn == 2) {
    add(1, 0); add(1, 1);
    return res;
  } else if(sn == 4){
    add(0, 1); add(0, 2); add(2, 0); add(3, 0); add(2, sn-1); add(3, sn-1);
    return res;
  }
  
  // borders
  
  // top
  for(int c = (i4 ? 1 : 2); c < sn-1; c += 4){
    add(0, c); add(0, c+1);
  }

  // bottom
  for(int c = (i4 ? 3: 0); c < sn-1; c += 4){
    add(sn-1, c); add(sn-1, c+1);
  }

  // sides
  for(int r = (i4 ? 2 : 1); r < sn-1; r += 4){
    add(r, 0); add(r+1, 0); add(r, sn-1); add(r+1, sn-1);
  }

  // recur to n-2 inner square
  return res^calc(of+2);
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> gd[i][j];

  cout << calc(0) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}

/*
Consider the following game: 
There is an n X n board of lights with all lights turned off. Each move, choosing square i, j,
toggles all edge-adjacent squares but not corner-adjacent squares or the chosen square itself.
Which squares should be picked to turn on the entire board on?

Recursive Pattern:
For each n, depending on 0/2 mod 4, tile the border w sets of 2, then recur to the inner n-2 square

Base Case:
n = 2
. .
# #

n = 4
# . . #
# . . #
. . . .
. # # .

Examples:
n=12 (0 mod 4)
. # # . . # # . . # # .
. . . . . . . . . . . .
# . . # # . . # # . . #
# . . . . . . . . . . #
. . # . . # # . . # . .
. . # . . . . . . # . .
# . . . # . . # . . . #
# . . . # . . # . . . #
. . # . . . . . . # . .
. . # . . # # . . # . .
# . . . . . . . . . . #
# . . # # . . # # . . #

n=10 (2 mod 4)
. . # # . . # # . .
# . . . . . . . . #
# . . . # # . . . #
. . # . . . . # . .
. . # . . . . # . .
# . . . # # . . . #
# . . . . . . . . #
. . # # . . # # . .
. . . . . . . . . .
# # . . # # . . # #
*/