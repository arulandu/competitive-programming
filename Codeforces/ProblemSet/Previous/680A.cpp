#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  map<int, int> m;
  map<int, int>::iterator itr;
  int s = 0;
  for(int i = 0; i < 5; i++){
    int x;
    cin >> x;
    s += x;
    itr = m.find(x);
    if(itr == m.end()){
      m[x] = 1;
    } else {
      m[x]++;
    }
  }
  int r = INT_MIN;
  for(itr = m.begin(); itr != m.end(); itr++){
    int first = itr->first;
    int second = itr->second;

    if(second >= 3){
      second = 3;
    }

    if(second < 2){
      second = 0;
    }

    r = max(r, first * second);
  }

  cout << s - r;

  return 0;
}
