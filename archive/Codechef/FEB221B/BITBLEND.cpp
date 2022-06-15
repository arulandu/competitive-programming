#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n; cin >> n;
  vector<int> a(n); for(int i= 0; i < n; i++) cin >> a[i];

  // par(a&b) != par(a|b) iff (a%2)^(b%2)=1 so a[i] is an alternating sequence of 0 and 1 in the first bit
  // ORDER MATTERS what if i change a 1? then im screwed!
  

  int mn = INT_MAX;
  pair<set<int>, set<int>> bst;
  for(int of = 0; of < 2; of++){
    set<int> e1;
    set<int> fp;
    for(int i = 0; i < n; i++){
      if(a[i]%2 == 1){
        e1.insert(i);
      }
      if((a[i]%2) != ((i+of)%2)){
        fp.insert(i);
      }
    }
    if((fp.size() == 0) || e1.size() > 0) {
      if(e1.size() == 1 && fp.count(*e1.begin()) > 0) continue;
      if(fp.size() < mn){
        mn = fp.size();
        bst.first = e1; bst.second = fp;
      }
    }
  }
  
  if(mn == INT_MAX){
    cout << -1 << "\n";
  } else {
    cout << mn << '\n';
    // for(auto x : a) cout << x << ' '; cout << '\n';
    for(auto f : bst.second){
      // if(a[f]%2==1) continue;
      int ef = -1;
      for(auto e : bst.first){
        if(e != f && a[e]%2==1){
          ef = e; break;
        }
      }

      assert(ef != -1);
      assert(ef != f);
      if(a[f]%2==1) bst.first.erase(f);
      a[f] = a[f]^a[ef];
      cout << (f+1) << ' ' << (ef+1) << '\n';
    }
    

    // for(auto x : a) cout << x << ' '; cout << '\n';
    for(int i = 0; i < n-1; i++){
      if((a[i]&a[i+1])%2==(a[i]|a[i+1])%2) {
        assert(false);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
