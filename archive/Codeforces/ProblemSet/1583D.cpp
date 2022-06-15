/*
Contest: Codeforces Technocup 2022 - Elimination Round 1
Problem: [D] Omkar and the Meaning of Life
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int qry(vector<int>& v){
  cout << "? "; for(auto x : v) cout << x+1 << ' '; cout << endl;
  int k; cin >> k; return k-1;
}

void ans(vector<int>& v){
  cout << "! "; for(auto x : v) cout << x << ' '; cout << endl;
}

void solve(){
  int n; cin >> n;
  vector<int> pm(n); for(int i = 0; i < n; i++) pm[i] = -1;

  vector<int> q(n, 0);

  // find pm[n-1] and indices of all values < pm[n-1]
  vector<int> l;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n; j++) q[j] = j == n-1 ? 0 : 1+i;
    int k = qry(q);
    if(k < 0) break;
    l.push_back(k);
  }

  pm[n-1] = l.size()+1;
  for(int i = 0; i < l.size(); i++){
    pm[l[i]] = l.size()-i;
  }

  // find indices of values > pm[n-1]
  q = vector<int>(n, 0);
  for(int i = 1; i <= n-pm[n-1]; i++){
    q[n-1] = i;
    int k = qry(q);
    pm[k] = l.size()+1+i;
  }

  ans(pm);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1; while(t--) solve();

  return 0;
}
