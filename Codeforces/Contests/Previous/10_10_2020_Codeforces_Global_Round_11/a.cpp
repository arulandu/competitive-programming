#include <bits/stdc++.h>

using namespace std;

// b - building , a - available
vector<int>& solve(vector<int> &a, vector<int> &b, int sum, int size){
  cout << sum << size << endl;
  if(b.size() >= size){
    return b;
  }

  for(int i = 0; i < a.size(); i++){
    int v = a.at(i);
    if(a.at(i) != sum*-1){
      b.push_back(v);
      a.erase(a.begin() + i);
      vector<int> &s = solve(a, b, sum + v, size);
      if(s.size() != 0){
        return s;
      }
    }

    a.insert(a.begin() + i, v);
    b.pop_back();
  }

  vector<int> s (0);
  return s;
}

/*
Greedy
keep picking numbers that don't make the sum zero - constructive
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;

      vector<int> a;
      for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
      }
      cout << 'x' << endl;

      vector<int> b;
      vector<int> &s = solve(a, b, 0, n);
      cout << 'x' << endl;
      if(s.size() <= 0){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        for(auto i : s){
          cout << i << ' ';
        }
        cout << endl;
      }
    }

    return 0;
}
