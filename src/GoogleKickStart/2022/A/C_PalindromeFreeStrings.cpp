/*
Contest: Google Kickstart Round A 2022
Problem: [C] Palindrome Free Strings
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool pal5(string s){
  return s[0] == s[4] && s[1] == s[3]; 
}

bool pal6(string s){
  return s[0] == s[5] && s[1] == s[4] && s[2] == s[3];
}

// O(2^(k+1)*n) -> O(n) DP where k=5 (minimum disallowed palindrome length)
bool solve(){
  int n; string s; cin >> n >> s;
  vector<vector<bool>> dp(n+1, vector<bool>(64, false)); // dp[i][last 5 digits in binary] = works? consider substrings up to i inclusive
 
  if(s.size() < 5) return true;

  // set true all matching binary strings of length 5 that aren't palindromes
  for(int x = 0; x < 32; x++){
    string xs = bitset<5>(x).to_string();
    if(pal5(xs)) continue;

    bool fg = true;
    for(int q = 0; q < 5; q++){
      if(s[q] != '?' && s[q] != xs[q]) {
        fg = false; break;
      }
    }
    
    if(fg) {
      dp[4][x] = true;
    }
  }

  // push dp
  for(int i = 4; i < n-1; i++) {
    bool fg = false;
    for(int x = 0; x < 64; x++){
      if(dp[i][x]){
        fg = true;
       
        int xp06 = (x << 1)+0, xp16 = (x << 1)+1; // & 011111
        int xp05 = xp06&((1<<6)-1), xp15 = xp16&((1<<6)-1);

        // use last 6 integers to place 0 if valid
        if(s[i+1] == '?' || s[i+1] == '0'){
          if(!pal6(bitset<6>(xp06).to_string()) && !pal5(bitset<5>(xp05).to_string())) {
            dp[i+1][xp05] = true;
          }
        }

        // similarly for placing 1
        if(s[i+1] == '?' || s[i+1] == '1'){
          if(!pal6(bitset<6>(xp16).to_string()) && !pal5(bitset<5>(xp15).to_string())) {
            dp[i+1][xp15] = true;
          }
        }        
      }
    }

    if(!fg) break;
  }

  // find if solutions exists
  for(int x = 0; x < 64; x++){
    if(dp[n-1][x]){
      return true;
    }
  }

  return false;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    cout << (solve() ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
  }

  return 0;
}
