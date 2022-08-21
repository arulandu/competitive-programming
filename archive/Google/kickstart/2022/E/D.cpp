#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MAXN = 10, MAXM = 20, MAXP = 10;
const ll inf = 1e18;
ll dp[MAXN][MAXN][MAXM+1][(1LL<<MAXP)]; // dp[r][c][m][p] = max coins at (r, c) after m minutes with p delivery bitmask
ll N, P, M;
pair<ll, ll> A;
map<pair<int, int>, pair<int, int>> cs; // cs[{r, c}] = {#, coins}

// STAY, NORTH, EAST, WEST, SOUTH 
const vector<pair<ll, ll>> deltas = {{0, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 0}};
vector<pair<char, ll>> tolls(5, {'+', 0}); 

// could've gotten top 200 if i didn't forget this :((
ll fdiv(ll x, ll d){
  return x < 0 ? (x-d+1)/d : x/d; // integer division for negatives
}

// compute toll from dir
ll toll(ll x, int dir){
  pair<char, ll> f = tolls[dir];
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

// O(N^2 * M * 2^P)
void solve(){
  // clear
  cs.clear();

  // read
  cin >> N >> P >> M >> A.first >> A.second;
  A.first--; A.second--;
  for(ll i = 1; i <= 4; i++) {
    cin >> tolls[i].first >> tolls[i].second;
  }
  for(int p = 0; p < P; p++) {
    pair<int, int> pos; cin >> pos.first >> pos.second;
    pos.first--; pos.second--;
    int x; cin >> x;
    cs[pos] = {p, x};
  }
  
  // init
  ll PS = 1LL << P;
  for(ll r = 0; r < N; r++){
    for(ll c = 0; c < N; c++){
      for(ll m = 0; m <= M; m++){
        for(ll p = 0; p < PS; p++){
          dp[r][c][m][p] = -inf;
        }
      }
    }
  }
  dp[A.first][A.second][0][0] = 0;

  // step through minutes
  for(ll m = 0; m < M; m++){
    for(ll r = 0; r < N; r++){
      for(ll c = 0; c < N; c++){
        for(ll p = 0; p < PS; p++){
          if(dp[r][c][m][p] != -inf){
            // check each direction
            for(int di = 0; di <= 4; di++){
              int rp = r + deltas[di].first, cp = c + deltas[di].second;
              if(rp >= 0 && cp >= 0 && rp < N && cp < N){
                // move + deliver
                if(cs.count({rp, cp}) == 1){
                  auto customer = cs[{rp, cp}];
                  if(((p >> customer.first) & 1LL) == 0LL){
                    ll pp = p | (1LL << customer.first);
                    ckmax(dp[rp][cp][m+1][pp], toll(dp[r][c][m][p], di)+customer.second);
                  }
                }

                // move. don't deliver
                ckmax(dp[rp][cp][m+1][p], toll(dp[r][c][m][p], di));
              }
            }
          }
        }
      } 
    }

  }

  // get best when pizza bitmask is all 1
  ll bst = -inf;
  ll FP = P == 0 ? 0 : (PS-1);
  for(ll r = 0; r < N; r++) {
    for(ll c = 0; c < N; c++){
      ckmax(bst, dp[r][c][M][FP]);
    }
  }

  // output
  if(bst == -inf) cout << "IMPOSSIBLE";
  else cout << bst;
  cout << '\n';
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
