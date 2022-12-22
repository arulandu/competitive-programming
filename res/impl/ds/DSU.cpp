#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent;
  vector<int> size;

  DSU(int n) {
    parent = vector<int>(n, -1);
    size = vector<int>(n, 0);
  }

  void make_set(int v){
    if(v < 0 || size[v] > 0){
      return;
    }

    parent[v] = v;
    size[v] = 1;
  }

  int find_set(int v){
    if(parent[v] == -1){
      return -1;
    }

    if(v == parent[v])
      return v;

    int p = find_set(parent[v]);
    parent[v] = p; // path compression
    return p;
  }

  void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
      // union by size
      if(size[a] < size[b]){
        parent[a] = b;
        size[b] += size[a];
      } else {
        parent[b] = a;
        size[a] += size[b];
      }
    }
  }
};
