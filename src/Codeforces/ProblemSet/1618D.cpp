/*
Contest: Codeforces Round #760 (Div. 3)
Problem: [D] Array and Operations
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, k; cin >> n >> k;
  vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  // i-th greatest and combine with i-th after last greatest k
  int s = 0;
  for(int i = n-1; i >= n-k; i--){
    if(a[n-k-1-(n-1-i)] == a[i]) s++;
  }

  // sum remaining
  for(int i = 0; i < n-2*k; i++) s += a[i];
  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
