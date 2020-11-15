#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<vector<char>>> bact;
  // O(m*k^2) < 10^7
  for(int i = 0; i < m; i++){
    vector<vector<char>> b;
    for(int r = 0; r < k; r++){
      vector<char> row;
      for(int c = 0; c < k; c++){
        char x;
        cin >> x;
        row.push_back(x);
      }
      b.push_back(row);
    }
    bact.push_back(b);
  }

  char out[n*k][n*k];
  // O (n^2*k^2) 2.5x10^7
  for(int r = 0; r < n; r++){
    for(int c = 0; c < n; c++){
      int x;
      cin >> x;
      for(int br = 0; br < k; br++){
        for(int bc = 0; bc < k; bc++){
          out[r*k+br][c*k+bc] = bact[x-1][br][bc];
        }
      }
    }
  }

  // O(n^2*k^2) 2.5x10^7
  for(int r = 0; r < n*k; r++){
    for(int c = 0; c < n*k; c++){
      cout << out[r][c];
    }
    cout << '\n';
  }


  return 0;
}
