/*
Contest: CodeChef Starters 21 Division 3
Problem: [C] Akash and Grid
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(){
  int n; pair<int, int> s; cin >> n >> s.first >> s.second;
  return s.first%2 != s.second%2;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
