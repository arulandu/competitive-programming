#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; ll x; cin >> n >> x;
  vector<ll> v(n); for(int i = 0; i < n; i++) cin >> v[i];
  multiset<ll> ms; for(auto r : v) ms.insert(r);

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int o = x-v[i]-v[j];
      if(ms.count(o) > ((int)(o == v[i]) + (int)(o == v[j]))){
        for(int k = j+1; k < n; k++){
          if(v[k] == o){
            cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
            return 0;
          }
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
