#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n; ll x; cin >> n >> x;
  vector<ll> p(n); for(int i = 0; i < n; i++) cin >> p[i];
  sort(p.begin(), p.end());
  int i = 0, j = n-1, c = 0;
  while(i <= j){
    if(p[j]+p[i] <= x) {
      c++; i++; j--;
    } else {
      c++; j--;
    }
  }
  cout << c << "\n";

  return 0;
}
