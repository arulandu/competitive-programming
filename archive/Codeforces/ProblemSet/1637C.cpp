/*
Contests: Codeforces Global Round 19
Problem: [C] Andrew and Stones
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  ll n; cin >> n;
  vector<ll> as(n);
  for(ll i = 0; i < n; i++) cin >> as[i];
  set<ll> ods;
  for(ll i = 1; i < n-1; i++) if(as[i]%2LL == 1LL) ods.insert(i);

  set<ll> st; for(ll i = 1; i < n-1; i++) st.insert(i);
  ll ops = 0; bool run = true;
  while(!st.empty()){
    ll i = *st.begin(); st.erase(st.begin());
    while(as[i] > 1){
      auto lit = ods.lower_bound(i), rit = ods.upper_bound(i);
      if(lit != ods.begin()){
        lit--;
        as[*lit]++; st.insert(*lit); as[n-1]++; as[i] -= 2; ops++; ods.erase(lit); 
      } else if(rit != ods.end()){
        as[*rit]++; st.insert(*rit); as[0]++; as[i] -= 2; ops++; ods.erase(rit);
      } else {
        ll op = as[i]/2LL; as[i] -= 2LL*op; as[0] += op; as[n-1] += op; ops += op;
        break;
      }
    }
    // cout << "i: " << i << " | "; for(auto a : as) cout << a << " "; cout << " | " << ops << "\n";
  }

  if(ods.size() > 0) {
    cout << -1 << '\n'; return;
  }

  for(ll i = 1; i < n-1; i++){
    ops += as[i]/2LL; as[i] = 0;
  }

  cout << ops << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
