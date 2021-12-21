#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<int, int>> pts(n);
  for(int i = 0; i < n; i++){
    cin >> pts[i].first >> pts[i].second;
  }
  
  int c = (n*(n-1)*(n-2))/6;
  // cout << c << '\n';
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      for(int k = j+1; k < n; k++){
        ld m1 = (pts[j].second-pts[i].second)/((ld)(pts[j].first - pts[i].first));
        ld m2 = (pts[k].second-pts[i].second)/((ld)(pts[k].first - pts[i].first));
        if(fabs(m1-m2) < 1e-8){
          // cout << i << ' ' << j << ' ' << k << '\n';
          c--;
        }
      }
    }
  }
  
  cout << c << '\n';

  return 0;
}
