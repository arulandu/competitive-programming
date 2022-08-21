#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int c = 2;
  int n, m; cin >> n >> m;
  if(n% 2== 0) c++;
  if(m%2==0) c++;
  cout << (c % 2 == 0 ? "Tonya" : "Burenka") << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
