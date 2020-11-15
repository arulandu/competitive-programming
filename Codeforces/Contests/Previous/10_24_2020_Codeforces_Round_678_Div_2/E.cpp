#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  bool lesAr[n];
  int ar[n];
  cout << "d\n";

  int prev = INT_MAX;
  bool foundOne = false;
  for(int i = 0; i < n; i++){
    cin >> ar[i];

    if(prev < ar[i]){
      lesAr[ar[i]]=true;
    } else if(prev>ar[i]){
      lesAr[prev]=true;
    }

    if(ar[i]==1){
      foundOne = true;
    }

    prev = ar[i];
  }
  cout << "d\n";
  if(foundOne){
    // minimum final of 3
    sort(ar, ar+n);
    int q = 0;
    for(int i = 0; i < n; i++){
      if(i+1!=ar[i]){
        break;
      } else {
        q++;
      }
    }
    bool f = false;
    for(int i = 3; i < q; i++){
      if(lesAr[i]){
        f = true;
        cout << i << '\n';
        break;
      }
    }
    if(!f){
      cout << q+1 << '\n';
    }
  } else {
    cout << 2 << '\n';
  }

  return 0;
}
