#include <bits/stdc++.h>

using namespace std;

int eval(string str){
  int s = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == 'W'){
      s++;
      if(i > 0 && str[i - 1] == 'W'){
        s++;
      }
    }
  }

  return s;
}

int solve(string str, int k){
  int i = str.find("WLW");
  while(i != string::npos && k > 0){
    str = str.substr(0, i) + "WWW" + str.substr(i+3, str.size() - (i + 3));
    k--;
    i = str.find("WLW");
  }

  i = min(str.find("LW"), str.find("WL"));
  while(i != string::npos && k > 0){
    str = str.substr(0, i) + "WW" + str.substr(i+2, str.size() - (i + 2));
    k--;
    i = min(str.find("LW"), str.find("WL"));
  }

  i = str.find("L");
  while(i != string::npos && k > 0){
    str = str.substr(0, i) + "W" + str.substr(i+1, str.size() - (i + 1));
    k--;
    i = str.find("L");
  }

  return eval(str);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    string str;
    int n;
    int k;
    cin >> n;
    cin >> k;
    cin >> str;
    cout << solve(str, k) << '\n';
  }

  return 0;
}
