/*
Contest: Codechef Starters 43
Problem: [A] Distinct Palindrome
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(){
  int n, x; cin >> n >> x;
  if(x > (n+1)/2){
    cout << -1 << '\n';
  } else {
    char c = 'a';
    string s(n, '0');
    for(int i = 0; i < (n+1)/2; i++){
      if(i < x){
        s[i] = c; s[n-1-i] = c;
        c++;
      } else {
        c = 'a';
        s[i] = c; s[n-1-i] = c;
      }
    }

    cout << s << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
