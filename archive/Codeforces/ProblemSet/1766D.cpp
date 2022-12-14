#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXN = 1e7;

// sieve for log(n) factoring. euclid. floors.
int spf[MAXN];
 
void sieve()
{
  spf[1] = 1;
  for (int i=2; i<MAXN; i++) spf[i] = i;
  for (int i=4; i<MAXN; i+=2) spf[i] = 2;
  for (int i=3; i*i<MAXN; i++) {
    if (spf[i] == i)
    {
      for (int j=i*i; j<MAXN; j+=i)
        if (spf[j]==j)
          spf[j] = i;
    }
  }
}

vector<int> factor(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void solve(){
  int x, y; cin >> x >> y;
  if(y < x) swap(x, y);
  int d = y-x;
  if(d == 1) {
    cout << -1 << '\n'; return;
  }
  auto fcts = factor(d);
  int mk = 1e9;
  for(auto f : fcts){
    int k = f*((x/f) + (x % f == 0 ? 0 : 1))-x;
    mk = min(mk, k);
  }
  cout << mk << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  sieve();

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
