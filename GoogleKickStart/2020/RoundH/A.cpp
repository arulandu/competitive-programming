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
  for(int f = 1; f <= t; f++){
    ll n, k, s;
    cin >> n >> k >> s;
    cout << "Case #" << f << ": ";

    ll rst = k-1+1+n;
    ll bck = k-1+k-s+n-s+1;
    // cout << rst << ' ' << bck << ' ';
    cout << min(rst, bck) << '\n';
  }

  return 0;
}
