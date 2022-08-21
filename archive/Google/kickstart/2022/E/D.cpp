#include <bits/stdc++.h>

using namespace std;
#define ll long long

// SUBTASK 1: Simulate dp

// could've gotten top 200 if i didn't forget this :((
ll fdiv(ll x, ll d){
  return x < 0 ? (x-d+1)/d : x/d;
}

// toll roads
ll toll(ll x, pair<char, ll> &f){
  if(f.first == '/'){
    return fdiv(x, f.second);
  } else if(f.first == '*'){
    return x*f.second;
  } else if(f.first == '-'){
    return x-f.second;
  } else if(f.first == '+'){
    return x+f.second;
  } else {
    assert(false);
    return -1;
  }
}

void ckmax(ll& target, ll val){
  target = max(target, val);
}

void solve(){
  // read
  const ll inf = 1e18;
  ll N, P, M;
  const ll MAXN = 10, MAXM = 20;
  pair<ll, ll> A;
  ll dp[MAXN][MAXN][MAXM+1];

  cin >> N >> P >> M >> A.first >> A.second;
  A.first--; A.second--;

  // NORTH, EAST, WEST, SOUTH | 0, 1, 2, 3
  vector<pair<char, ll>> tolls(4);
  for(ll i = 0; i < 4; i++) {
    cin >> tolls[i].first >> tolls[i].second;
  }

  // init
  for(ll r = 0; r < N; r++){
    for(ll c = 0; c < N; c++){
      for(ll m = 0; m <= M; m++){
        dp[r][c][m] = -inf;
      }
    }
  }
  dp[A.first][A.second][0] = 0;

  ll bst = 0;

  // simulate toll nav
  for(ll m = 0; m < M; m++){
    for(ll r = 0; r < N; r++){
      for(ll c = 0; c < N; c++){
        assert(dp[r][c][m] >= -inf);
        if(dp[r][c][m] != -inf){
          if(r > 0)   ckmax(dp[r-1][c+0][m+1], toll(dp[r][c][m], tolls[0]));
          if(c < N-1) ckmax(dp[r+0][c+1][m+1], toll(dp[r][c][m], tolls[1]));
          if(c > 0)   ckmax(dp[r+0][c-1][m+1], toll(dp[r][c][m], tolls[2]));
          if(r < N-1) ckmax(dp[r+1][c+0][m+1], toll(dp[r][c][m], tolls[3]));
          
          ckmax(bst, dp[r][c][m]);
          dp[r][c][m+1] = max(dp[r][c][m+1], dp[r][c][m]);
        }
      }
    }
  }

  // get best
  for(ll r = 0; r < N; r++) {
    for(ll c = 0; c < N; c++){
      ckmax(bst, dp[r][c][M]);
    }
  }
  cout << bst << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
