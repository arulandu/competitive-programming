#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  int n;
  cin >> n;
  priority_queue<string, vector<string>, greater<string>> pq;
  // O(nlogn) - O(n^2)
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x == 1){
      string w;
      cin >> w;

      pq.push(w); // O(log(n))
    } else if(x==2){
      queue<string> tmp;
      int c = 0;
      string q;
      cin >> q;
      while(!pq.empty()){
        string s = pq.top();
        // cout << "s: " << s << " q: " << q << "\n";
        int cmp = strcmp(s.substr(0, q.length()).c_str(), q.c_str());
        if(cmp == 0){ // O(1)
          c++;
        } else if(cmp > 0){ // O(1)
          // cout << cmp << "x\n";
          break;
        }
        tmp.push(s); // O(1)
        pq.pop(); // O(logn)
      }

      // restore pq
      while(!tmp.empty()){
        pq.push(tmp.front()); // O(logn)
        tmp.pop(); // O(1)
      }

      cout << c << '\n';
    }
  }

  return 0;
}

/*
pq
add word to pq
if 2 then pop off counting until u find something past, add all the popped ones back in

*/
