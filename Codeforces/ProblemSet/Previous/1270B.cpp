#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    vector<int> ar;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      ar.push_back(x);
    }

    bool f = false;
    for(int i = 0; i < n-1; i++){
      if(abs(ar.at(i) - ar.at(i+1)) >= 2){
        f = true;
        cout << "YES" << endl;
        cout << i+1 << " " << i+2 << endl;
        break;
      }
    }
    if(!f){
      cout << "NO" << endl;
    }

  }
  return 0;
}
