#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  string s; cin >> s;
  int Q; cin >> Q;

  // x - y = other(x, y)
  auto other = [](char x, char y){
    if(x == 'B') return y;
    if(y == 'B') return x;
    if(x == y) return 'B';

    if((x == 'O' && y == 'W') || (x == 'W' && y == 'O')) return 'C';
    if((x == 'O' && y == 'C') || (x == 'C' && y == 'O')) return 'W';
    if((x == 'C' && y == 'W') || (x == 'W' && y == 'C')) return 'O';

    assert(false);
    return '!';
  };

  string pf(s.size(), ' ');
  
  for(int i = 0; i < s.size(); i++){
    pf[i] = other(i > 0 ? pf[i-1] : 'B', s[i]);
  }

  for(int q = 0; q < Q; q++){
    int l, r; cin >> l >> r; r--; l--;
    char res = other(pf[r], l > 0 ? pf[l-1] : 'B');
    cout << (res == 'C' ? 'Y' : 'N');
  }
  cout << '\n';

  return 0;
}
