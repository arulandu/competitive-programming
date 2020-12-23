#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5+1;
const ll maxXY = 1e8 + 1;

int N, M;
vector<pair<ll, ll>> cows (MAX); // stores coordinates of all cows
vector<int> adj [MAX]; // stores graph (adjacency lists)
bool visited[MAX]; // visited array keeps track of if a node is previously visited in dfs

// handles input output to file or terminal
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

// dfs's on node and returns the largest bounding box for its children and the current node
pair<pair<int, int>, pair<int, int>> dfs(int node){
  visited[node] = true;
  pair<pair<int, int>, pair<int, int>> bounds = make_pair(make_pair(cows[node].first, cows[node].first), make_pair(cows[node].second, cows[node].second)); // set bounds to coords of node
  for(auto x : adj[node]){
    if(!visited[x]){
      pair<pair<int, int>, pair<int, int>> p = dfs(x); // get bounds of child
      // update bounds to be the largest
      bounds.first.first = min(p.first.first, bounds.first.first);
      bounds.first.second = max(p.first.second, bounds.first.second);
      bounds.second.first = min(p.second.first, bounds.second.first);
      bounds.second.second = max(p.second.second, bounds.second.second);
    }
  }

  return bounds; // return largest bounds
}

// calculate the perimeter of each strongly connected component and return min
int findMin(){
  ll minPer = 2e18;
  for(int i = 1; i <= N; i++){
    if(!visited[i]){
      pair<pair<int, int>, pair<int, int>> p = dfs(i); // run dfs to get largest bounds
      ll per = 2*(p.first.second - p.first.first + p.second.second - p.second.first); // calculate perimeter from bounds
      minPer = min(minPer, per);// update min perimeter
    }
  }
  return minPer;
}


int main(){
  handle_io(true, "fenceplan");

  // read input
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    cin >> cows[i].first >> cows[i].second;
  }

  // construct graph
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout << findMin() << '\n'; // return minimum perimeter

  return 0;
}

/*
7 5
0 5
10 5
5 0
5 10
6 7
8 6
8 4
1 2
2 3
3 4
5 6
7 6
*/
