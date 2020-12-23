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
  cout << "inf: ";
  for(int i = 1; i <= N; i++){
    cout << infected[i] << ", ";
  }
  cout << '\n';
}

void printVis(vector<bool> &vis){
  cout << "vis: ";
  for(int i = 1; i <= N; i++){
    cout << vis[i] << ", ";
  }
  cout << '\n';
}

int dfs(int node, int prev, bool isDouble, vector<bool> &visited){
  visited[node] = true;
  vector<bool> tmpv = visited;
  vector<int> tmpi (maxN);
  tmpi = infected;

  c++;
  if(c > 20){
    return -500;
  }
  cout << "node: " << node << " prev: " << prev << " isDouble: " << isDouble << '\n';
  printInf();
  printVis(visited);
  for(int i = 1; i <= N; i++){
    if(infected[i] < 1){
      goto skip;
    }
  }
  return 0;
  skip:;

  if(infected[node] >= min(2*N, INT_MAX) || infected[node] <= 0){
    return INT_MAX;
  }

  int md = INT_MAX;
  if(adj[node].size() <= 1){
    return dfs(prev, -1, false, visited);
  }

  for(auto x : adj[node]){
    if(!visited[x] && infected[node] > 1 && (isDouble || prev != x)){
      // move cow
      infected[node]--;
      infected[x]++;
      md = min(1+dfs(x, node, false, visited), md);
      infected = tmpi;
      visited = tmpv;
    }
  }

  // double
  infected[node] *= 2;
  md = min(md, 1+dfs(node, node, true, visited));
  infected = tmpi;
  visited = tmpv;


  return md;
}

int main(){
  // cin.tie(0);
  // ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 0; i < N-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= N; i++){
    cout << i << ": ";
    for(auto x : adj[i]){
      cout << x << ' ';
    }
    cout << '\n';
  }

  infected[1]++;
  vector<bool> visited (N);
  cout << dfs(1, -1, false, visited) << '\n';
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

Idea:
- start at farm 1
- dfs through and add the number of nodes that come out other than the prev => log base 2
- sum ^^ + number of nodes
*/
