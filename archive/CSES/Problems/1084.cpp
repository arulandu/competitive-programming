#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m; ll k; cin >> n >> m >> k;
  vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i];
  vector<ll> b(m); for(int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end()); sort(b.begin(), b.end());
  int i = 0, j = 0, c = 0;
  while(i < n && j < m){
    while(j < m && b[j] < a[i]-k) j++;
    if(j >= m) continue;
    if(b[j] > a[i]+k){ i++; } else {c++; i++; j++;}
  }

  cout << c << '\n';

  return 0;
}
