#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

int main(){
  handle_io(true);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    ll c = 1;
    for(int i = 0; i < n; i++){
      c *= 4;
    }
    cout << c << "\n";
  }


  return 0;
}

/*
2
1
3
*/
