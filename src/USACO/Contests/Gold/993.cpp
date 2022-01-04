/*
Contest: USACO 2020 January Gold
Problem: [1] Time is Mooney
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

int dp[500][1000]; // dp[i][j] = max after i+1 days ending at city j 
vector<int> adj[1000];

int main(){
  io(true, "time");

  // read input build graph
  int n, m, c; cin >> n >> m >> c;
  vector<int> ms(n); for(int i = 0; i < n; i++) cin >> ms[i];
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b);
  }

  // bound t using math 500 is around the max of this bound for constraints
  int mxm = -1; for(auto m : ms) mxm = max(mxm, m);
  int mt = ceil(0.5*(mxm/c+1));

  for(int i = 0; i <= mt; i++){
    for(int j = 0; j < n; j++){
      dp[i][j] = i == 0 ? 0 : INT_MIN; // init
    }
  }

  for(int i = 0; i <= mt; i++){
    for(int j = 0; j < n; j++){
      // can only travel if this city is reachable or it's day 1 and this is city 1
      if((i == 0 && j != 0) || dp[i][j] == INT_MIN) continue;

      // travel to diff city
      for(auto v : adj[j]){
        dp[i+1][v] = max(dp[i+1][v], dp[i][j]+ms[v]-c*(2*(i+1)-1));
      }
    }
  }

  // max over ith-length trips ending at city 1
  int ans = INT_MIN;
  for(int i = 1; i <= mt; i++){
    ans = max(ans, dp[i][0]);
  }

  cout << ans << '\n';

  return 0;
}
