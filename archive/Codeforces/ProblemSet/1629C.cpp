/*
Contest: Codeforces Round #767 (Div. 2)
Problem: [C] Meximum Array
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> as(n); for(int i = 0; i < n; i++) cin >> as[i];
  
  // {value, index} for searching first occurrence of particular value after index j with lower_bound
  multiset<pair<int, int>> ms;
  for(int i = 0; i < n; i++) ms.insert({as[i], i});

  vector<int> bs;
  
  // iterate through bs
  int j = 0;
  while(j < n){
    int lk = 0; set<int> fnd;
    auto it = ms.begin();
    while(lk <= n){
      it = ms.lower_bound({lk, j});

      // lk (looking for) not found
      if(it == ms.end() || it->first != lk){
        if(lk == 0) j++;
        break;
      }
      
      // move pointer to location and update found
      while(j <= it->second) {
        fnd.insert(as[j]);
        j++;
      }
      
      // get next value to search for
      int pv = -1;
      auto it = fnd.lower_bound(lk);
      while(it != fnd.end()){
        if(pv >= 0){
          if(*it > pv+1) {
            lk = pv+1;
            break;
          }
        }
        pv = *it;
        it++;
      }
      if(lk != pv+1) lk = pv+1;
    }

    // if lk not found, lk is the MEX and continue w a new segment
    bs.push_back(lk);
  }

  cout << bs.size() << '\n'; for(auto b : bs) cout << b << ' '; cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
