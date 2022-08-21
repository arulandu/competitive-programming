#include <bits/stdc++.h>

using namespace std;
#define ll long long

// manacher's algorithm: is substring a palindrome? in O(n)
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res), end(res));
}

bool pal(string &s, vector<int> &man, int l, int r){
  if((r-l)%2 == 1){
    // odd pali
    int m = (l+r)/2;
    int z = man[2*m+1]/2;
    if(2*z-1 >= (r-l)) return true;
  } else {
    // even pali
    int m = (l+r+1)/2;
    int z = (man[2*m]-1)/2;
    if(2*z >= (r-l)) return true;
  }
  return false;
}

void solve(){
  int n; cin >> n;
  string s; cin >> s;
  auto man = manacher(s);

  // find first i such that both s[:i] and s[i:] are palindromes. then q = s[:i]
  string q = "";
  for(int i = 1; i <= n; i++){
    if(i == n || (pal(s, man, 0, i) && pal(s, man, i, n))){
      q = s.substr(0, i); break;
    }
  }

  cout << q << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
