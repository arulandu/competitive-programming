#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; ll x; cin >> n >> x;
  vector<ll> v(n); for(int i = 0; i < n; i++) cin >> v[i];
  multiset<ll> s; for(auto r : v) s.insert(r);
  for(int i = 0 ; i < n; i++){
    if(s.count(x-v[i]) > (x == 2*v[i] ? 1 : 0)){
      for(int j = 0; j < n; j++){
        if(j != i && v[j] == (x-v[i])){
          cout << i+1 << ' ' << j+1 << '\n';
          return 0;
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
