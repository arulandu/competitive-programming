#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n-1; i++){
      cin>>v[i];
  }
  int a, b; cin >> a >> b;

    int s = 0;
  for(int i = a-1; i < b-1; i++){
      s += v[i];
  }

cout << s << '\n';
  return 0;
}
