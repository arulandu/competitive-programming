/*
Contest: Codeforces Round #761 [Div. 2]
Problem: [D1] Too Many Impostors (easy version)
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool query(int a, int b, int c){
  cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
  int x; cin >> x; return x == 1;
}

void ans(vector<int> &v){
  cout << "! "; cout << v.size() << ' '; for(auto x : v) cout << x+1 << ' '; cout << endl;
}

void solve(){
  int n; cin >> n;
  int imp[n]; for(int i = 0; i < n; i++) imp[i] = 0; // 0 if unknown, -1 for imp, 1 for crew

  // 3 element sliding window
  bool p = query(0, 1, 2); 
  for(int i = 1; i < n; i++){
    bool q = query(i, (i+1)%n, (i+2)%n);
    if(q != p){
      // if consec windows disagree, i-1 / (i+2)%n are fixed and opposite by subtraction of inequalities
      imp[i-1] = p ? 1 : -1; imp[(i+2)%n] = -imp[i-1];

      // use these two fixed and opposite elements against all other unknowns
      for(int j = 0; j < n; j++) if(imp[j] == 0) imp[j] = query(i-1, (i+2)%n, j) ? 1 : -1;
      break;
    }

    p = q;
  }

  // print imposters
  vector<int> imps; for(int i = 0; i < n; i++) if(imp[i] == -1) imps.push_back(i);
  ans(imps);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
