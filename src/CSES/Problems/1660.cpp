#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, x; cin >> n >> x;
  map<ll, int> s2i; s2i[0] = -1;
  vector<ll> pf(n);
  for(int i = 0; i < n; i++){
    cin >> pf[i]; pf[i] += i > 0 ? pf[i-1] : 0;
    s2i[pf[i]] = i;
  }

  int c = 0;
  for(auto l : s2i) if(s2i.count(l.first-x) && s2i[l.first-x] < l.second) c++;
  cout << c << '\n';

  return 0;
}
