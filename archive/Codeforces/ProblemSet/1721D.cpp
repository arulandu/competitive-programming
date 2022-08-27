/*
Contest: Educational Codeforces Round 134 (Div. 2)
Problem: [D] Maximum AND
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// Time Complexity: O(N*log(N)*B)? idk
// Space Complexity: O(N)

const int MAXB = 31;
const int MAXN = 1e5;
int n;
vector<int> a(MAXN), b(MAXN);

// check bth bit of n
bool ckb(int n, int b){
  return ((n >> b)&1) == 1;
}

// binary search: returns first i in rng s.t. bth bit of p[i] is 1
int bsone(vector<int> &p, pair<int, int> rng, int bit){  
  int l = rng.first, r = rng.second;
  if(!ckb(p[r], bit)) return rng.second+1;
  while(l < r){
    int m = (l+r)/2;
    if(ckb(p[m], bit)){
      r = m;
    } else {
      l = m+1;
    }
  }

  return l;
}

void solve(){
  // read
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i]; for(int i = 0; i < n; i++) cin >> b[i];
  
  // solve one bit at a time
  int ans = 0;
  set<pair<pair<int, int>, pair<int, int>>> q; q.insert({{0, n-1}, {0, n-1}}); // maintain map ranges, {arng, brng}
  for(int bit = MAXB-1; bit >= 0; bit--){
    int num = q.size();
    bool good = true;
    stack<pair<pair<int, int>, pair<int, int>>> splits, preserve;
    stack<pair<pair<int, int>, pair<int, int>>> nxt;

    for(auto rngs : q){
      auto arng = rngs.first, brng = rngs.second;
      assert(arng.second-arng.first == brng.second-brng.first); // bijectable

      // sort range by only considering rhs bits    
      int mask = (1LL << (bit+1))-1;
      sort(a.begin()+arng.first, a.begin()+arng.second+1, [&mask](auto i1, auto i2){return (mask&i1) < (mask&i2);});
      sort(b.begin()+brng.first, b.begin()+brng.second+1, [&mask](auto i1, auto i2){return (mask&i1) < (mask&i2);});

      int aone = bsone(a, arng, bit), bone = bsone(b, brng, bit);
      if(aone-arng.first == brng.second-bone+1 && arng.second-aone+1 == bone-brng.first){
        // # of zeros in A = # ones in B i.e. complementary
        // possible split candidate
        splits.push({{arng.first, aone-1}, {bone, brng.second}});
        splits.push({{aone, arng.second}, {brng.first, bone-1}});
        preserve.push(rngs);
      } else {
        // not-splittable
        good = false; 
        nxt.push(rngs);
      }
    }

    // add map ranges
    q.clear();
    while(!nxt.empty()){ q.insert(nxt.top()); nxt.pop(); }

    if(good) {
      // if all ranges are splittable, split
      ans += (1LL << bit);
      while(!splits.empty()){ q.insert(splits.top()); splits.pop(); }
    } else {
      // otherwise, use fallback
      while(!preserve.empty()){ q.insert(preserve.top()); preserve.pop();}
    }
  }

  // answer
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
