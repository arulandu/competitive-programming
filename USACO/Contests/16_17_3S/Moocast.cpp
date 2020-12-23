#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long;

const int maxN = 201;
int N;
vector<int> adj[maxN];

// stores cow data
struct Cow {
  int x, y, p;
};

// handles io
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

// does dfs on a node and returns count
int dfs(int node, vector<bool> &visited){
  int c = 1;
  visited[node] = true;
  for(auto x : adj[node]){
    if(!visited[x]){
      c += dfs(x, visited);
    }
  }
  return c;
}

// returns max count by dfs on all N nodes
int count(){
  int m = 0;
  for(int i = 0; i < N; i++){
    vector<bool> visited (maxN); // create visited array of all false
    m = max(m, dfs(i, visited)); // update max
  }
  return m;
}

int main(){
  handle_io(true, "moocast");

  // read input
  cin >> N;
  vector<Cow> cows (N);
  for(int i = 0; i < N; i++){
      cin >> cows[i].x >> cows[i].y >> cows[i].p;
  }

  // loop throug all pairs of cows
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      // calculate distance
      float d = sqrt(pow(cows[i].x - cows[j].x, 2) + pow(cows[i].y - cows[j].y, 2));

      // update adj list based on power
      if((float)cows[i].p >= d){
          adj[i].push_back(j);
      }
      if((float)cows[j].p >= d){
        adj[j].push_back(i);
      }
    }
  }

  cout << count() << '\n'; // print max count
  return 0;
}

/*
PLAN:
1. loop through all pairs and form graph with adj lists
2. dfs from each node and count the number of cows that can be reached
3. find max value of ^
*/
