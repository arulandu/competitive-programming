#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  ll s = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    s += x;
  }

  ll s1 = 0;
  for(int i = 0; i < n-1; i++){
    int x;
    cin >> x;
    s1 += x;
  }
  cout << s - s1 << '\n';
  s = s1;
  s1 = 0;
  for(int i = 0; i < n-2; i++){
    int x;
    cin >> x;
    s1 += x;
  }
  cout << s-s1 << '\n';


  return 0;
}
