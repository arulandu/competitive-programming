#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  map<int, int> m;
  map<int, int>::iterator iter;

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    iter = m.find(x);
    if(iter != m.end()){
      iter->second = iter->second + 1;
    } else {
      m.insert(pair<int, int>(x, 1));
    }
  }

  int mx = INT_MIN;
  for(iter = m.begin(); iter != m.end(); iter++){
    mx = max(iter->second, mx);
  }
  cout << mx << endl;

  return 0;
}
