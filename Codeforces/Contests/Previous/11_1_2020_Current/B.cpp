#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(a+b, c+d) << '\n';
  }

  return 0;
}

/*
a - 100th for contest 1
c - 100th for contest 2
d - 1-100th in 2 have a have a minimum of d in 1st
b - 1-100th in 1 have a minimum of b in 2nd

.....99....a.... : 1st
bbbb..100..bbbb....: hypo 2nd
= > total score is a+b

.....99....c.... : 2nd
ddddd..100..dddd.....: hypo 1st
= > total score is c + d
*/
