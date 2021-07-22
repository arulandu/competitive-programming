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

  string ds[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};


  map<string, double> m;
  for(int i = 0; i < 16; i++){
    m.insert(make_pair(ds[i], 22.5*i));
  }

  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string x;
    cin >> x;
    cout << x << " is " << m[x] << ((m[x] == (int)m[x])? ".0":"") << " degrees\n";
  }

  return 0;
}

/*
16
N
NNE
NE
ENE
E
ESE
SE
SSE
S
SSW
SW
WSW
W
WNW
NW
NNW
*/
