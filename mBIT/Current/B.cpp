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

  int n, m;
  cin >> n >> m;

  vector<vector<int>> piles (m);
  for(int i = 0; i < m; i++){
    int r;
    cin >> r;
    vector<int> p (r);
    for(int j = 0; j < r; j++){
      cin >> p[j];
    }
    piles[i]=p;
  }

  vector<pair<int, int>> actions;

  // move all stones to pile 2
  for(int i = 0; i < m; i++){
    if(m != 1){
      for(int x : piles[m]){
        actions.push_back(make_pair(i+1, 2));
        piles[1].push_back(x);
      }

      piles[m].clear();
    }
  }

  // move type 1 stones to pile 1 and all others to pile 3
  for(int x : piles[1]){
    if(x == 1){
      actions.push_back(make_pair(2, 1));
      piles[0].push_back(x);
    } else {
      actions.push_back(make_pair(2, 3));
      piles[2].push_back(x);
    }
  }
  piles[1].clear();

  // move all from pile 3 to pile 1
  for(int x : piles[2]){
    actions.push_back(make_pair(3, 1));
    piles[0].push_back(x);
  }
  piles[2].clear();

  // sort stones to according piles from pile 1
  for(int x : piles[0]){
    if(x == 1){
      break;
    } else {
      actions.push_back(make_pair(1, x));
    }
  }

  cout << actions.size() << '\n';
  for(pair<int, int> x : actions){
    cout << x.first << ' ' << x.second << '\n';
  }


  return 0;
}

/*
3 3
2 1 2
1 3
0
*/
