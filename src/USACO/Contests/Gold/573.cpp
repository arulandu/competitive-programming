/*
Contest: USACO 2015 December Gold
Problem: #1 High Card Low Card
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

// count max points in high card
int count(vector<int>& es, vector<int>& bs){
  sort(es.begin(), es.end(), greater<int>());
  sort(bs.begin(), bs.end(), greater<int>());
  
  // two pointers: use bessie's best card on highest elsie card that it can beat
  int i = 0, j = 0, c = 0;
  while(i < bs.size() && j < es.size()){
    while(j < es.size() && es[j] > bs[i]) j++;
    if(j < es.size()) {
      c++; j++; i++;
    }
  }

  return c;
}

int main(){
  io(true, "cardgame");

  // read input and calculate elsie's 1st/2nd round cards
  int n; cin >> n;
  set<int> tmp; set<int> bs; vector<int> es1(n/2), es2(n/2), bs1(n/2), bs2(n/2);
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    if(i < n/2) {
      es1[i] = x;
    } else {
      es2[i-n/2] = x;
    }
    tmp.insert(x);
  }

  // of not chosen cards, bessie's 1st round are the n/2 highest and 2nd round are n/2 lowest
  for(int i = 1; i <= 2*n; i++) if(!tmp.count(i)) bs.insert(i);
  auto bit = bs.begin();
  for(int i = 0; i < n; i++){
    if(i < n/2){
      bs2[i] = *bit;
    } else {
      bs1[i-n/2] = *bit;
    }
    bit++;
  }

  // low card game = high card game w all elements negated
  for(int i = 0; i < n/2; i++){ es2[i] *= -1; bs2[i] *= -1; }

  // sum counts for first and last n/2 rounds
  cout << (count(es1, bs1) + count(es2, bs2)) << '\n';

  return 0;
}
