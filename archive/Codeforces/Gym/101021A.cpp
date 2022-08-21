#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool geq(int x){
  cout << x << endl;
  string s; cin >> s;
  if(s[0] == '<') return false;
  return true;
}

void guess(int x){
  cout << "! " << x << endl;
}

void solve(){
  int l = 1, r = 1000000;
  while(l < r){
    int m = (l+r+1)/2;
    if(geq(m)){
      l = m;
    } else {
      r = m-1;
    }
  }  

  guess(l);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
