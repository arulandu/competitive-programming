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

int dist(int a, int e, int n){
  if(a < e){
    return min(e-a, a+n-e);
  } else if(a > e){
    return min(a-e, e+n-a);
  } else {
    return 0;
  }
}

int main(){
  handle_io(true);

  ll d;
  cin >> d;
  for(int di = 1; di <= d; di++){
    int n, p, s;
    cin >> n >> p >> s;

    map<string, pair<int, bool>> m;
    for(int i = 0; i < n; i++){
      string x;
      cin >> x;
      m.insert(make_pair(x, make_pair(i, false)));
    }
    string pres[p];
    for(int i = 0; i < p; i++){
      cin >> pres[i];
      m[pres[i]].second = true;
    }

    // cout << "debug\n";
    // for(auto x : m){
    //   cout << x.first << ": " << x.second.first << ' ' << x.second.second << '\n';
    // }
    // cout << "debug\n";

    cout << "Day #" << di << ":\n";
    for(int i = 0; i < s; i++){
      string b, e;
      cin >> b >> e;
      int mi = dist(m[b].first, m[e].first, n);
      for(int j = 0; j < p; j++){
        mi = min(mi, 1+dist(m[pres[j]].first, m[e].first, n));
      }

      cout << mi << '\n';
    }

    if(di != d){
      cout << '\n';
    }
  }

  return 0;
}

/*
2
2 1 1
88.5 107.9
88.5
88.5 107.9
11 3 3
89.9 90.1 90.5 92.3 93.7 94.9 95.3 96.7 97.5 98.3 101.1
92.3 94.9 97.5
89.9 101.1
101.1 92.3
94.9 90.1
*/
