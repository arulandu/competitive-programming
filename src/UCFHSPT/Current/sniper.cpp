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
    int n, k;
    cin >> n >> k;
    ll h[n];
    ll b[k];
    ll ha[n];
    ll he[n];

    ll s = 0;
    for(int i = 0; i < n; i++){
      cin >> h[i];
      s += h[i];
      ha[i] = (h[i]>0) + (i==0?0:ha[i-1]);
      he[i] = (h[i]<0) + (i==0?0:he[i-1]);
    }
    for(int i = 0; i < k; i++){
      cin >> b[i];
    }

    // cout << "p\n";
    // // debg
    // for(int i = 0; i < n; i++){
    //   cout << ha[i] << ' ';
    // }
    // cout << '\n';
    //
    // for(int i = 0; i < n; i++){
    //   cout << he[i] << ' ';
    // }
    // cout << '\n';
    // //debg
    // cout << "p\n";

    for(int i = 0; i < k; i++){
      if(ha[b[i]-1] > he[b[i]-1]){
        s += ha[b[i]-1]-he[b[i]-1];
      }
    }
    cout << s << '\n';
  }

  return 0;
}

/*
2
6 5
3 -2 -4 1 5 -1
3 5 4 1 3
1 2
-1
1 1
*/
