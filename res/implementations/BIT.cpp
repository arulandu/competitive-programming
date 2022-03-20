#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct BIT {
  vector<ll> s;
  int n;

  public:
  BIT(int N): s(N+1, 0), n{N}{}

  int lsb(int x) { return x & -x; }
  // update index i
  void update(int i, int delta){
    for(++i; i < s.size(); i += lsb(i)) s[i] += delta;
  }

  // sum range [0, i]
  ll query(int i) {
    ll sum = 0;
    for(++i; i > 0; i -= lsb(i)) sum += s[i];
    return sum;
  }
};
