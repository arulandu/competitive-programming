#include <bits/stdc++.h>

using namespace std;

int* solve(int* ar, int n){
  sort(ar, ar + n);
  do {
      int s = 0;
      bool f = true;
      for(int j = 0; j < n; ++j){
        if(s == -1*ar[j]){
          f = false;
          break;
        }
        s += ar[j];
      }

      if(f){
        return ar;
      }

  } while (next_permutation(ar, ar + n));
  return NULL;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;

      int ar[50];
      for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ar[i] = x;
      }

      int* s = solve(ar, n);

      if(s == NULL){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
          cout << s[i] << ' ';
        }
        cout << endl;
      }
    }

    return 0;
}
