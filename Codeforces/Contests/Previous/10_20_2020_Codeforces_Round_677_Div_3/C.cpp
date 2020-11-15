#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    int ar[n];
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
      cin >> ar[i];
      mx = max(ar[i], mx);
    }

    for(int i = 0; i < n; i++){
      if(ar[i] == mx && ((i > 0 && ar[i-1] != mx) || (i < n-1 && ar[i+1] != mx))){
        cout << i + 1 << '\n';
        goto end;
      }
    }
    cout << -1 << '\n';
    end:;
  }

  return 0;
}

/*

[5, 3, 4, 4, 5]

if only 1 pirana
  is a dom

if one side is lower,
  remove that side and add 1 to the current
if 2 sides are lower,
  remove both sides and add 2 to the current
else
  not a dom
recur
*/
