/*
Contest: Codeforces Round #190 (Div. 1)
Problem: [B] Ciel and Duel
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
vector<int> atks, defs; multiset<int> cls;

// "defense case": beat all cards and use highest remaining to deal extra damage
int def(multiset<int> cds){
  // beat defense with lowest cards > d
  int c = 0;
  for(auto d : defs){
    auto it = cds.upper_bound(d);
    if(it == cds.end()) return -1;
    cds.erase(it);
  }

  // beat atks with lowest card >= a (add pts)
  for(auto a : atks){
    auto it = cds.lower_bound(a);
    if(it == cds.end()) return -1;
    c += *it-a; cds.erase(it);
  }

  // use remaining (highest damage feasible)
  for(auto cd : cds) c += cd;

  return c;
}

// attack as many attacks as possible
int atk(multiset<int> cds){
  // beat smallest atks with largest card for highest delta
  int c = 0;
  for(auto a : atks){
    if(cds.size() < 1) break;
    auto it = --cds.end();
    if(*it < a) break;
    c += *it-a; cds.erase(it);
  }

  return c;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  // read input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string s; cin >> s; int r; cin >> r;
    if(s == "ATK"){
      atks.push_back(r);
    } else {
      defs.push_back(r);
    }
  }
  for(int i = 0; i < m; i++) { int x; cin >> x; cls.insert(x); }

  // sort attacks increasing
  sort(atks.begin(), atks.end());

  // use max of both strategies  
  cout << max(def(cls), atk(cls)) << '\n';
  
  return 0;
}
