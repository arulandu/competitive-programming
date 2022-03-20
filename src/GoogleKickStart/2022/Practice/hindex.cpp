#include <bits/stdc++.h>

using namespace std;
#define ll long long

template <class T, int... ArgsT> struct BIT {
  T val = 0;
  
  void update(T v) {
    val += v;
  }
  
  T query() {
    return val;
  }
};

template <class T, int N, int... Ns>
struct BIT<T, N, Ns...> {
  BIT<T, Ns...> bit[N+1];

  template<typename... Args>
  void update(int pos, Args... args) {
    for (; pos <= N; pos += lsb(pos)) bit[pos].update(args...);
  }

  template<typename... Args>
  T sum(int r, Args... args) {
    T res = 0;
    for(; r >= 1; r -= lsb(r)) res += bit[r].query(args...);
    return res;
  }

  template<typename... Args>
  T query(int l, int r, Args... args) {
    return sum(r, args...) - sum(l-1, args...);
  }

  int lsb(int v){
    return v & (-v);
  }
};

const int MAXC = 100001;

void solve(){
  int n; cin >> n;
  vector<int> cs(n); for(int i = 0; i < n; i++) cin >> cs[i];

  BIT<int, MAXC> bit;
  auto ck = [&](int h){
    return bit.query(h, MAXC) >= h;
  };

  // O(n) = n*log(n)*log(c) // iterate + binary search + fenwick
  for(int i = 0; i < n; i++){
    bit.update(cs[i], 1);

    int l = 0, r = n;
    while(l < r){
      int m = l+(r-l+1)/2;
      if(ck(m)){
        l = m;
      } else {
        r = m-1;
      }
    }

    cout << l << ' ';
  }
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
