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

  int n;
  cin >> n;
  int odd = 0;
  int even = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x % 2 == 0){
      even++;
    } else {
      odd++;
    }
  }

  cout << min(odd, even) << '\n';

  return 0;
}

/*
2 3 3 2 3 3
(2, 3) (3, 2)

*/
