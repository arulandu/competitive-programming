#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

/*
    Combine the time and direction into one array, sort ascending by time.
    Create two queues for exit and enter and simply go through the array and
    implement the rules. Use the queues to represent the lines and simulate index
    until the queues have elements, then iterate in time until the next indexed time 
    with the queues. Repeat until just queues are left in which case step through time
    till finished.
    
    Time: O(n*log(n))
    Space: O(n)
*/
vector<int> solve(int n, const vector<int>& t, const vector<int>& d){
    // skipped implementation cuz it's boring
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  

  vector<int> ans = solve(4, {0, 0, 1, 5}, {0, 1, 1, 0});
  cout << "[";
  for(auto x : ans){
      cout << x << ", ";
  }
  cout << "]";
  return 0;
}
