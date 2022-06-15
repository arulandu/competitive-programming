/*
Contest: Codeforces Round #762 (Div. 3)
Problem: [D] New Year's Problem
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int m, n; cin >> m >> n;
  int p[m][n]; for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> p[i][j];

  // for each each friend, choose max
  int sh[n];
  for(int i = 0; i < n; i++){
    sh[i] = 0;
    for(int j = 0; j < m; j++){
      if(p[j][i] > p[sh[i]][i]){
        sh[i] = j;
      }
    }
  }

  // find min of max, if n > m we can always choose best for each friend
  int s = INT_MAX; for(int i = 0; i < n; i++) s = min(s, p[sh[i]][i]);
  if(n > m) return s;

  // since n-1 shops, one shop is given for a pair of friends. find max of the min joys for each pair for each shared shop
  int pmx = INT_MIN;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int mx = INT_MIN;
      for(int k = 0; k < m; k++){
        mx = max(mx, min(p[k][i], p[k][j]));
      }
      pmx = max(mx, pmx);
    }
  }

  // if pmx < s, the min joy changed otherwise a high joy changed so the min is the same
  return min(pmx, s);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
