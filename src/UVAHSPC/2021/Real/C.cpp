#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

char ar[24];

struct Pos {
  int a, b, c;
};

int count(char a, char b, char c, char target){
  return (int)(a == target) + (int)(b == target) + (int)(c == target);
}

int calc(Pos& p){
  char a = ar[p.a - 1], b = ar[p.b - 1], c = ar[p.c - 1];
  int bonus = 0;
  int cF = count(a, b, c, 'F'), cS = count(a, b, c, 'S'), cG = count(a, b, c, 'G'), cI = count(a, b, c, 'I'), cW = count(a, b, c, 'W'), cL = count(a, b, c, 'L');
  if(cL > 0 && cI > 0){
    bonus += cW > 0 ? 5 : 3;
  }

  bonus += 4*(int)(cF > 0 && cS > 0);
  bonus += 6*(int)(cG > 0 && cI > 0);

  return cL*4 + cW*6 + cF*3 + cS*2 + cG*5 + cI*4 + bonus;
}

void solve(){
  int j = 0;
  char c;
  while(j < 19){
    cin >> c;
    if(isalpha(c)){
      ar[j] = c;
      j++;
    }
  }

  vector<Pos> pos = {
    {1, 2, 5},
    {1, 3, 5},
    {2, 4, 7},
    {2, 5, 7},
    {3, 5, 8},
    {3, 6, 8},
    {4, 7, 9},
    {5, 7, 10},
    {5, 8, 10},
    {6, 8, 11},
    {7, 9, 12},
    {7, 10, 12},
    {8, 10, 13},
    {8, 11, 13},
    {9, 12, 14},
    {10, 12, 15},
    {10, 13, 15},
    {11, 13, 16},
    {12, 14, 17},
    {12, 15, 17},
    {13, 15, 18},
    {13, 16, 18},
    {15, 17, 19},
    {15, 18, 19}
  };
  // for(auto x : ar){
  //   cout << x << ' ';
  // }
  // cout << '\n';
  vector<int> s;
  for(auto p : pos){
    int c = calc(p);
    s.push_back(c);
  }
  
  sort(s.begin(), s.end(), greater<>());
  // for(auto x : s){
  //   cout << x << ' ';
  // }
  // cout << '\n';
  cout << s[2*3+1-1] << '\n';
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  for(int t = 1; t <= n; t++){
    solve();
  }

  return 0;
}

/*
2
     _     
   _/G\_   
 _/F\_/G\_ 
/G\_/I\_/I\
\_/L\_/L\_/
/F\_/F\_/F\
\_/S\_/I\_/
/W\_/I\_/F\
\_/W\_/G\_/
  \_/F\_/  
    \_/    
     _     
   _/S\_   
 _/I\_/I\_ 
/S\_/S\_/W\
\_/I\_/G\_/
/W\_/G\_/I\
\_/G\_/S\_/
/F\_/W\_/G\
\_/I\_/S\_/
  \_/L\_/  
    \_/    
*/