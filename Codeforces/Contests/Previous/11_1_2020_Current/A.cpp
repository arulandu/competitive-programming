#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, x;
    cin >> n >> x;

    int a[n];
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }

    int b[n];
    for(int i = 0; i < n; i++){
      cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n, greater<int>());

    for(int i = 0; i < n; i++){
      if(a[i] + b[i] > x){
        cout << "No\n";
        goto skip;
      }
    }
    cout << "Yes\n";
    skip:;
  }

  return 0;
}

/*
-5 10 10 -15
-5 10 10 -15   x = 3
for i in n
  ai + bi <= x

sum(a) + sum(b) <= x*n
2 2 2
3 3 3

*/
