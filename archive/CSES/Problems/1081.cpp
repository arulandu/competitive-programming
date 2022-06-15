#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXX = 1e6;
int cnt[MAXX+1];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  for(int i = 0; i < n; i++){int x; cin >> x; cnt[x]++;}
  for(int g = MAXX; g >= 0; g--){
    int c = 0;
    for(int m = g; m <= MAXX; m += g){
      c += cnt[m];
    }
    if(c >= 2){
      cout << g << '\n';
      break;
    }
  }

  return 0;
}
