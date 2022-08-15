#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXN = 1000;
int n;

vector<int> shoot(){
  vector<vector<bool>> closed(MAXN, vector<bool>(MAXN, false));
  // [r, c] where r is the position in the permutation and c is the value

  vector<int> seq;
  for(int c = 0; c < n; c++){
    // pick random valid moves
    vector<int> pos; for(int r = 0; r < n; r++) {if(!closed[r][c]) pos.push_back(r);}
    if(pos.size() == 0) return seq;
    int r = pos[rand()%pos.size()];
    
    // block corresponding triples
    for(int cs = 0; cs < seq.size(); cs++){
      int rs = seq[cs]; 
      int rt = 2*r-rs, ct = 2*c-cs;
      if(rt >= 0 && rt < n && ct >= 0 && ct < n) closed[rt][ct] = true;
    }

    // block same col/row
    for(int t = 0; t < n; t++) if(t != c) closed[r][t] = true;
    for(int t = 0; t < n; t++) if(t != r) closed[t][c] = true;

    seq.push_back(r);
  }

  return seq;
}

void solve(){
  cin >> n;

  // simulate until sequence is found: turns out this takes 1-2 iterations usually, why? i have no clue
  while(true){
    auto seq = shoot();
    if(seq.size() == n){
      for(auto x : seq) cout << (x+1) << " "; cout << "\n";
      return;
    }  
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}
