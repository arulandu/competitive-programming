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
  handle_io(true, "bcount");

  int n, q;
  cin >> n >> q;
  int ar[n];
  for(int i = 0; i < n; i++){
    cin >> ar[i];
  }

  // cout << "x\n";
  vector<vector<int>> ps (3);
  // cout << "x\n";
  for(int i = 0; i < 3; i++){
    vector<int> p (n);
    // cout << "x\n";
    for(int j = 0; j < n; j++){
      int s = ((ar[j] == i+1) ? 1 : 0);
      if(j == 0){
        p[0] = s;
        // cout << "x\n";
        continue;
      }

      p[j] = s + p[j-1];
      // cout << "x\n";
    }
    // cout << "x\n";
    ps[i] = p;
  }
  // cout << "x\n";
  //
  // for(int i = 0; i < 3; i++){
  //   cout << "prefix: " << i << "\n";
  //   for(auto x : ps[i]){
  //     cout << x << ' ';
  //   }
  //   cout << "\n\n";
  // }

  for(int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    for(int j = 0; j < 3; j++){
      cout << ps[j][b-1]-((a-2)<0 ? 0 : ps[j][a-2]);
      if(j != 2){
        cout << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}

/*
6 3
2
1
1
3
2
1
1 6
3 3
2 4
*/
