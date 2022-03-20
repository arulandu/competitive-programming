#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int c = 0;
  for(int i = 0; i < s.size()/2; i++){
    if(s[i] != s[s.size()-1-i]) c++;
  }

  return k >= c && (s.size() % 2 == 1 || (k-c)%2 == 0);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}
