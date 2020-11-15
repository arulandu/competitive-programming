#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  int s = 0;
  for(int i = 0; i < n; i+=2){
    s += max(v.at(i), v.at(i+1));
  }

  cout << s << endl;

  return 0;
}
