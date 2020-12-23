#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e5 + 1;
int N;
vector<int> adj[maxN];
vector<int> infected (maxN);
int c = 0;

void printInf(){
  for(int i = 1; i <= N; i++){
    cout << infected[i] << ", ";
  }
  cout << '\n';
}

int main(){
  // cin.tie(0);
  // ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 0; i < N-1; i++){
    int a, b;
    cin >> a >> b;
  }
  int d = rint(ceil(log2(N)));
  d += N-1;
  cout << d;
  return 0;
}


/*
4
1 2
1 3
1 4

1 strong component
no cycles

Subtasks:
1-4 => double and then spread
5-7

Postulate:
 first infect the backbone in the easiest way, then spread to leaves
Infecting Backbone:
 - backbone is a line
 - calc how many doubles you need, then place extra

 Simulate???
 - dfs and simul moving 1 or double
*/
