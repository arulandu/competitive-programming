/*
Contest: CodeChef Starters 21 Division 3
Problem: [H] Magical Subsequence
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// Current: O(NQ) TODO: O(N*sqrt(Q)) https://discuss.codechef.com/t/msub121-editorial/97554
void solve(){
  int n; cin >> n;
  vector<int> as(n); for(int i = 0; i < n; i++) cin >> as[i];
  int q; cin >> q;
  vector<pair<int, int>> qrs(q); for(int i = 0; i< q; i++) cin >> qrs[i].first >> qrs[i].second;

  int mxv = INT_MIN;
  for(auto x : as) mxv = max(mxv, x); for(auto qr : qrs) mxv = max({mxv, qr.first, qr.second});

  vector<int> adj[mxv+2];
  // int freq[mxv+2];

  for(auto qr : qrs) {
    adj[qr.first].push_back(qr.second);
    // freq[qr.second]++;
  }

  map<int, set<int>> v2i; for(int i = 0; i < n; i++) v2i[as[i]].insert(i);

  int el[n]; for(int i = 0; i < n; i++) el[i] = -1;
  int dp[n]; // dp[i] = len lcs ending at i (not counting first element)
  int dpv[mxv+2];
  for(int i = 0; i < n; i++) dp[i] = 0;
  for(int i = 0; i < n; i++){
    // if(freq[as[i]] <= sqrt(q)){
      for(auto nb : adj[as[i]]){
        auto it = v2i[nb].upper_bound(i); if(it == v2i[nb].end()) continue;
        int v = dp[i]+1;
        if(v > dp[*it]){
          dp[*it] = v; el[*it] = i;
        }
      }
    // } else {
    //   dp[i] = dpv[as[i]];
    // }
    
    // cout << i << " | ";
    // for(int i = 0; i < n; i++) cout << dp[i] << ' '; cout << " | ";
    // for(int i = 0; i < n; i++) cout << el[i] << ' '; cout << " | ";
    // cout << '\n';
  }

  pair<int, int> mxp = {-1, INT_MIN};
  for(int i = 0; i < n; i++){
    if(dp[i] > mxp.second){
      mxp.second = dp[i];
      mxp.first = i;
    }
  }

  stack<int> st;
  do {
    st.push(mxp.first);
    mxp.first = el[mxp.first];
  } while(mxp.first != -1);

  cout << st.size() << '\n';
  while(!st.empty()){ cout << st.top()+1 << ' '; st.pop(); }
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
