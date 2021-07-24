#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

bool solve(){
  int n, m, k; cin >> n >> m >> k;
  if(k < 0 || k > (n*m)/2)
    return false;

  if(n % 2 == 0){
    return k%2==0 && k <= n*(m/2);
  } else {
    return k >= m/2 && (k-m/2)%2 == 0;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    cout << (solve() ? "YES" : "NO") << '\n';
  }

  return 0;
}

/*
1
2 1 0
--


*/
