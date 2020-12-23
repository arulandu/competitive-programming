#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

const int maxNM = 3001;
int N, M;
vector<int> adj[maxNM]; // stores graph
set<int> closed; // stores closings - used during calculation
int closings[maxNM]; // stores all closings in order
vector<bool> visited (maxNM); // stores if node is visited by dfs
vector<bool> falses (maxNM); // array of falses for restoration

// handles input output to file/terminal
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

// counts the number of nodes that can be reached from a given node without touching a closed node
int dfs(int node){
  int c = 1;
  visited[node] = true; // update visited
  for(auto x : adj[node]){
    if(!visited[x] && closed.count(x) <= 0){
      c += dfs(x); // update count with a dfs on child if the child is not closed nor visited
    }
  }

  return c;
}

int main(){
  handle_io(true, "closing");

  cin >> N >> M;

  // construct graph
  for(int i = 0; i < M; ++i){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // read in closings permutation
  for(int i = 0; i < N; i++){
    cin >> closings[i];
  }

  for(int i = 0; i < N; i++){
    int c = dfs(closings[N-1]); // dfs on last closing
    visited = falses; // restore visited array
    cout << (c==N-i ? "YES" : "NO") << "\n"; // output if fully connected
    closed.insert(closings[i]); // append closing to closing set
  }

  return 0;
}

/*
4 3
1 2
2 3
3 4
3
4
1
2
*/
