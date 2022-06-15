#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

int N, M;

queue<pair<int, int>> q;
queue<pair<int, int>> bq;
pair<int, int> e;
int grid[N][M]; // 1: wall, 2: poached, 0: unpoached, 3: goal

void vet_push(queue<pair<int, int>> &qu, pair<int, int> el){
  if(el.first >= 0 && el.first < N && el.second >= 0 && el.second < M && grid[el.first][el.second] != 1){
    qu.push(el);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; i++){
    string s; cin >> s;
    for(int j = 0; j < M; j++){
      if(s[i] == '#'){
        grid[i][j] = 1;
      } else if(s[i] == '-'){
        if(i == 0 || i == N-1 || j == 0 || j == M-1){
          grid[i][j] = 3;
        } else {
          grid[i][j] = 0;
        }
      } else if(s[i] == 'P'){
        grid[i][j] = 2;
        q.push({i, j});
      } else if(s[i] == 'B'){
        bq.push({i, j});
      }
    }
  }

  for(int d = 0; ;d++){
    int level = q.size();
    for(int i = 0; i < level; i++){
      auto p = q.front(); q.pop();
      vet_push(q, {p-1, q});
      vet_push(q, {p+1, q});
      vet_push(q, {p, q+1});
      vet_push(q, {p, q-1});
    }

    level = bq.size();
    for(int i = 0; i < level; i++){
      auto p = bq.front(); bq.pop();
      if(grid[p.first][p.second] == 3){}

      vet_push(bq, {p-1, q});
      vet_push(bq, {p+1, q});
      vet_push(bq, {p, q+1});
      vet_push(bq, {p, q-1});
    }
  }

  return 0;
}

// poaching