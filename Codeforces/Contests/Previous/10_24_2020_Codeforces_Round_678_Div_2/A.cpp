#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      sum += x;
    }
    if(sum == m){
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
