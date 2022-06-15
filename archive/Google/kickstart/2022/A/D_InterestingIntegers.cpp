/*
Contest: Google Kickstart Round A 2022
Problem: [D] Interesting Integers
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXN = 1e5;
int itst[MAXN+1];

// TODO: currently have dumb prefix sums solution for subtask 1.
void pre() {
  for(int i = 1; i <= MAXN; i++){
    ll pd = 1, sm = 0;
    
    int x = i;
    while(x != 0) {
      int dg = x%10;
      pd *= dg; sm += dg;
      x /= 10;
    }

    itst[i] = (int)(pd%sm == 0);
  }

  itst[0] = 0;
  for(int i = 1; i <= MAXN; i++){
    itst[i] += itst[i-1];
  }
}

void solve(){
  ll a, b; cin >> a >> b;
  cout << (itst[b]-itst[a-1]) << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  pre();

  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
