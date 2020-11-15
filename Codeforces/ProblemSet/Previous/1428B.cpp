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
    vector<char> v;
    vector<bool> ret;
    bool clo = true;
    bool aclo = true;
    int co = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == '>' && aclo){
          aclo = false;
        }

        if(c == '<' && clo){
          clo = false;
        }

        v.push_back(c);
        ret.push_back(false);
    }

    if(aclo || clo){
      cout << n << '\n';
    } else {
      for(int i = 0; i < n; i++){
        if(v.at(i) == '-'){
          ret.at(i % n) = true;
          ret.at((i+1)%n) = true;
        }
      }
      co = 0;
      for(bool x : ret){
        if(x){
          co++;
        }
      }

      cout << co << '\n';
    }


  }
  return 0;
}
