#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MOD = 1e9+7;

void solve(){
  // idea: simul with an array. get it working. then simul m times. memoize. then jump every m then simul rest. 
  // O(m+n/m): choose m around 10^5

  map<int, vector<int>> mp;
  ll n, k, m; cin >> n >> k >> m;
  string s; cin >> s;

  ll cnts[10][10];
  for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) cnts[i][j] = 0;

  for(ll x = 0; x < 10; x++){
    ll nx = x*k;
    while(nx > 0){
      cnts[x][nx%10]++;
      nx /= 10;
    }
  }

  cout << "cnts: " << '\n';
  for(int x = 0; x < 10; x++){
    for(int y = 0; y < 10; y++){
      cout << cnts[x][y] << ' ';
    }
    cout << "\n";
  }

  for(int mi = 0; mi <= m; mi++){
    mp[mi] = vector<int>(10, 0);
    if(mi == 0){
      for(int x = 0; x < 10; x++) mp[mi][s[x]-'0']++;
    } else {
      for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
          mp[mi][y] += cnts[x][y]*mp[mi-1][x];
        }
      }
    }

    cout << "mi: " << mi << '\n';
    for(int x = 0; x < 10; x++) cout << mp[mi][x] << ' '; cout << '\n';
  }

  int sm = 0;
  for(int x = 0; x < 10; x++) sm += mp[m][x];
  cout << sm << '\n';
}

int main(){
  // ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
