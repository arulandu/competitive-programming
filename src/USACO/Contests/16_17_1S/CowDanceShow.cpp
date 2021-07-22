#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int max_n = 10000;
int n;
ll t_max;
int ar[max_n];
const bool debug = true;

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

// total time taken for stage with size k
ll val(int k){
    ll t = 0; // timer
    priority_queue<ll, vector<ll>, greater<ll>> pq; // lowest end time at top

    // add first k elements to pq
    int i = 0;
    for(; i < k; i++){
        pq.push(ar[i]+t);
    }

    while(!pq.empty()){
        // remove top element from stack
        ll d = pq.top();
        pq.pop();
        t = d; // update timer

        // replace with next element
        if(i < n){
            pq.push(ar[i]+t);
            i++;
        }
    }

    return t;
}

int main(){
    handle_io(true, "cowdance");

    cin >> n >> t_max;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    // binary search on k in range [1, n] - find minimum k such that val(k) <= t_max
    int l = 1;
    int r = n;
    while(l <= r){
        int m = (l+r)/2;
        if(val(m) <= t_max){
            r = m-1;
        } else {
            l = m+1;
        }
    }
    
    // print minimum - (l contains answer after binary search)
    cout << l << '\n';

    return 0;
}
