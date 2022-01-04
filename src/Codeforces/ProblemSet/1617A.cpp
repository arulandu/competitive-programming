/*
Contest: Codeforces Round #761 (Div. 2)
Problem: [A] Forbidden Subsequence
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

string solve(){
  string s1, s2; cin >> s1 >> s2;
  sort(s1.begin(), s1.end());
  
  int p1 = 0, p2 = 0;
  while(p1 < s1.size() && p2 < s2.size()){
    if(s2[p2] == s1[p1]) p2++;
    p1++;
  }

  if(p2 < s2.size() && p1 >= s1.size()) return s1;
  int f1 = s1.find_first_of(s2[s2.size()-2]), l1 = s1.find_last_of(s2[s2.size()-2]);
  int f2 = s1.find_first_of(s2[s2.size()-1]), l2 = s1.find_last_of(s2[s2.size()-1]);
  // cout << s1 << " | " << f1 << " " << l1 << ' ' << f2 << ' ' << l2 << '\n';
  return s1.substr(0, f1)+s1.substr(f2, l2-f2+1)+s1.substr(f1, l1-f1+1)+s1.substr(l2+1);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
