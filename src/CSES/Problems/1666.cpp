#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long;

const int maxN = 1e5+10; // maximum value of N is 10^5
int N, M, rep[maxN]; // rep contains representative nodes
vector<int> adj[maxN]; // holds graph
bool visited[maxN]; // if each node is visited or not

// carry out dfs and update visited
void dfs(int node){
  visited[node] = true;
  for(auto x : adj[node]){
    if(!visited[x]){
      dfs(x);
    }
  }
}

// try to dfs at every node if not visited - counting components
int count(){
  int c = 0;
  for(int i = 1; i <= N; i++){
    if(!visited[i]){
      rep[c] = i;
      dfs(i);
      c++;
    }
  }
  return c;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  // build graph with adj lists
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int c = count(); // count the number of components
  cout << (c-1) << '\n';

  // take representatives of each component and connect them in a line
  for(int i = 0; i < c-1; i++){
    cout << rep[i] << ' ' << rep[i+1] << '\n';
  }

  return 0;
}

/*
4 2
1 2
3 4
*/
