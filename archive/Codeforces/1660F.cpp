#include <bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>
struct BIT {
  vector<T> s;
  int n;

  public:
  BIT(int N): s(N+1, 0), n{N}{}

  int lsb(int x) { return x & -x; }
  // update index i
  void update(int i, int delta){
    for(++i; i < s.size(); i += lsb(i)) s[i] += delta;
  }

  // sum range [0, i]
  T sum(int i) {
    T sum = 0;
    for(++i; i > 0; i -= lsb(i)) sum += s[i];
    return sum;
  }

  T query(int l, int r){
    return sum(r)-sum(l-1);
  }
};

const int MAXN = 2e5;

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> pf(n, 0);
  for(int i = 0; i < n; i++){
    pf[i] = (s[i] == '+' ? 1 : -1) + (i > 0 ? pf[i-1] : 0);
  }

  // find pf[i]s that are congruent in mod 3, store inds and query: how many elements in set > k
  // use BIT to answer query by maintaining count of each possible pf[i] in range [-n, n] (shift +n in indexing)
  vector<BIT<int>> mds(3, BIT<int>(2*n+1));
  mds[0].update(n, 1);

  ll tot = 0;
  for(int i = 0; i < n; i++){
    for(int m = 0; m < 3; m++){
      int pm = pf[i] % 3; 
      if((pm >= 0 ? pm : pm+3) == m){
        tot += (ll) mds[m].query(pf[i]+n, 2*n);
        mds[m].update(pf[i]+n, 1);        
        break;
      }
    }
  }

  cout << tot << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while(t--) solve();

  return 0;
}
