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
  map<string, int> ma;
  int c = 0;
  priority_queue<string, vector<string>, greater<string>> pq;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      string x;
      cin >> x;
      if(ma.count(x) > 0){
        ma[x] += 1;
        if(ma[x] == n){
          c++;
          pq.push(x);
        }
      } else {
        ma.insert(make_pair(x, 1));
      }
    }
  }

  cout << pq.size() << '\n';
  while(!pq.empty()){
    cout << pq.top() << '\n';
    pq.pop();
  }


  return 0;
}
