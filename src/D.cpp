/*
Contest: Codechef Starters 54 (Div. 3)
Problem: [D] K Flip
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MOD = 1e9+7;
const int MAXN = 1e5+1;
int m2[MAXN];

// precompute powers of 2 mod M
void pre(){
  m2[0] = 1;
  for(int i = 1; i <= MAXN; i++){
    m2[i] = (2*m2[i-1])%MOD;
  }
}

void solve(){
  int n, k; cin >> n >> k;
  string s; cin >> s;

  if(n == k){
    cout << 2 << '\n';
  } else if(k % 2 == 1){
    // odd can isolate one bit => 2**n
    cout << m2[n] << '\n';
  } else {
    // nC0 + nC2 + nC4 + .. + nCn = 2**(n-1)
    cout << m2[n-1] << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  pre();
  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
