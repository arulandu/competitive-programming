#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

set<char> vs {'a', 'e', 'i', 'o', 'u'};

int score(const string&s){
  int c = 0;
  for(int i = 0; i < s.length(); i++){
    if(vs.count(s[i]) > 0){
      c += 1;
    } else if(s[i]=='y'){
      c += 2;
    }
  }
  return c;
}

bool cmp(const string&s1, const string&s2){
  int c1 = score(s1);
  int c2 = score(s2);

  if(c1==c2){
    return s1 < s2;
  } else {
    return c1 > c2;
  }
}


int main(){
  handle_io(true);

  ll c;
  cin >> c;
  for(int i = 1; i <= c; i++){
    int s;
    cin >> s;
    string snacks[s];
    for(int j = 0; j < s; j++){
      cin >> snacks[j];
    }

    sort(snacks, snacks+s, cmp);

    cout << "Cabinet #" << i << ":\n";
    for(int j = 0; j < s; j++){
      cout << snacks[j] << '\n';
      // cout << snacks[j] << ' ' << score(snacks[j]) << '\n';
    }
    if(i != c){
      cout << '\n';
    }
  }

  return 0;
}

/*
2
3
pretzels
gum
chips
1
licorice
*/
