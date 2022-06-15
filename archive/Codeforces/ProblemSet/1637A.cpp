/*
Contests: Codeforces Global Round 19
Problem: [A] Sorting Parts
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n;
  vector<ll> as(n); for(int i = 0; i < n ;i++) cin >> as[i];
  vector<ll> tmp = as;
  sort(tmp.begin(), tmp.end());
  for(int i = 0; i < n; i++){
    if(tmp[i] != as[i]) return true;
  }

  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
