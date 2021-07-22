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

  vector<int> a(n);
  deque<int> b(n);
  for(int i = 0; i < n; i++){
     cin >> a[i];
  }
  for(int i = 0; i < n; i++){
     cin >> b[i];
  }

  while(true){
    // permute b
    b.push_front(b.back);
    b.pop_back();

    int d = 0;
    for(int i = 0; i < n; i++){
      d += abs()
    }
  }


  return 0;
}

/*
4
1 4 2 3
2 4 3 1 


*/
