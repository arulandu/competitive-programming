/*
Contest: Educational Codeforces Round 130
Problem: [C] awoo's Favorite Problem
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool solve(){
  int n; cin >> n;
  string s, t; cin >> s >> t;

  // left-to-right pass
  for(int i = 0; i < n; i++){
    if(i < n-1){
      if(s[i] != t[i]){
        if(s[i] == 'b' && t[i] == 'c'){
          // chain swap through b's to a c
          int j = i+1; while(j < n && s[j] == 'b') j++;
          if(j >= n || s[j] != 'c') return false;
          swap(s[i], s[j]);
        } else if(s[i] == 'a' && t[i] == 'b'){
          // chain swap through a's to a b
          int j = i+1; while(j < n && s[j] == 'a') j++;
          if(j >= n || s[j] != 'b') return false;
          swap(s[i], s[j]);
        } else {
          // no possible swap
          return false;
        }
      }
    } else {
      // final character doesn't work
      if(s[i] != t[i]) return false;
    }
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << (solve() ? "YES" : "NO") << '\n';

  return 0;
}
