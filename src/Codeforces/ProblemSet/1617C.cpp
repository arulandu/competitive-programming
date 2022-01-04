/*
Contest: Codeforces Round #761 (Div. 2)
Problem: [C] Paprika and Permutation
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n; cin >> n;
  vector<ll> as(n); for(int i = 0; i < n; i++) cin >> as[i];
  sort(as.begin(), as.end());
  
  bool pb[n+1]; for(int i = 1; i <= n; i++) pb[i] = false;
  bool b[n]; for(int i = 0; i < n; i++) b[i] = false;
  
  for(int i = 0; i < n; i++){
    if(as[i] >= 1 && as[i] <= n && !pb[as[i]] && !b[i]) {
      pb[as[i]] = true; b[i] = true;
    }
  }

  int op = 0;
  int pbi = n, ai = n-1;
  while(pbi >= 1 && ai >= 0){
    // cout << pbi << ' ' << ai << " | ";
    while(pbi >= 1 && pb[pbi]) pbi--;
    while(ai >= 0 && b[ai]) ai--;
    if(pbi < 1 || ai < 0) break;

    if(pbi <= (as[ai]-1)/2) {
      // cout << "c " << as[ai] << " -> " << pbi << '\n';
      pb[pbi] = true; b[ai] = true; op++;
    } else {
      return -1;
    }

  }


  if(pbi >= 1 != ai >= 0) return -1;

  return op;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
