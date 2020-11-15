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
    int rows[n][m];
    vector<set<int>> rowsets;
    int cols[m][n];
    for(int r = 0; r < n; r++){
      for(int c = 0; c < m; c++){
        cin >> rows[r][c];
        rowsets[r].insert(rows[r][c]);
      }
    }
    for(int c = 0; c < m; c++){
      for(int r = 0; r < n; r++){
        cin >> cols[c][r];
      }
    }

    int ord[n];
    for(int j = 0; j < n; j++){
      for(int s = 0; s < n; s++){
        bool f = true;
        for(int c = 0; c < m; c++){
          if(rowsets[s].count(cols[c][j]) <= 0){
            f = false;
            break;
          }
        }
        if(f){
          ord[j] = s;
          rowsets.erase(rowsets.begin() + s);
          break;
        }
      }
    }

    for(int o = 0; o < n; o++){
      for(int c = 0; c < m; c++){
        cout << rows[ord[o]][c] << ' ';
      }
      cout << '\n';
    }

  }

  return 0;
}

/*
rows:
1 2  3  7 -> sets
6 5  4  8
9 12 13 14

cols:
2 5 12
3 4 13
1 6 9
7 8 14



*/
