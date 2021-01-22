#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main(){
    bool debug = false;
    handle_io(false, "herding");

    // read input
    int n;
    cin >> n;
    vector<ll> ar (n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    // sort ascending
    sort(ar.begin(), ar.end());    

    // stores min answer = min empty spaces in an size-n interval
    int ans_mn = INT_MAX;

    // edge cases - n-1 consecutive cows & more than 2 spaces between other cow
    if(ar[n-2]-ar[0] == n-2 && ar[n-1]-ar[n-2]>2){
        ans_mn = 2;
    } else if(ar[n-1]-ar[1] == n-2 && ar[1]-ar[0]>2){
        ans_mn = 2;
    } else {
        // 2 pointers method
        int l = 0;
        int r = 0;
        for(;l < n; l++){
            // move right pointer
            while(r < n-1 && ar[r+1]-ar[l]-1<=n-2){
                r++;
            }
            ans_mn = min(ans_mn, n-(r-l+1)); // update min spaces in interval
        }
    }
    
    // max = total number of spaces - minimum enpoint spaces
    ll ans_mx = max(ar[n-2]-ar[0]+1, ar[n-1]-ar[1]+1)-(n-1);

    // print answers
    cout << ans_mn << '\n';
    cout << ans_mx << '\n';

    return 0;
}

/*
STRATEGY:
min:
- find min spaces in interval of length n starting at a number
- answer is simply the # of min spaces as x spaces can be filled in x moves
- Exceptions:
    - for n-1 consecutive cows and >2 spaces between the other is an edge case
    - the other cow cannot move directly to the end of the consecutive row.
    - This should return 2 separately (method ^^ would return 1).

max:
- find min # of spaces between an endpoint and the nearest number to the endpoint
- subtract ^ from total spaces
*/
