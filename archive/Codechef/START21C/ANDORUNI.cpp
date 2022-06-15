/*
Contest: CodeChef Starters 21 Division 3
Problem: [D] And or Union
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXB = 31; // 10^9 fits in 31 bits (really 30 but extra for safety lol)

ll solve(){
  int n; cin >> n;
  vector<ll> as(n); for(int i = 0; i < n; i++) cin >> as[i];
  
  // bt[b] = # of elements with b-th bit set
  int bt[MAXB]; for(int i = 0; i < MAXB; i++) bt[i] = 0;
  for(int i = 0; i < MAXB; i++){
    for(auto x : as){
      if((x>>i)&1) bt[i]++;
      if(bt[i] > 1) break; // ignore counting above 1 to save time
    }
  }


  // set bits in result
  ll ors = 0;
  for(int i = 0; i < MAXB; i++) if(bt[i] > 1) ors += (1 << i);
  
  return ors;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}

/*
Insight: 
(A|B)|C=A|B|C
Suppose each element has one bit. Notice that the OR product of pairwise AND is 1 iff there is more than one 1 in the array.
So for any size element, the kth bit of output value is 1 iff the # of elements with the kth bit set is > 1; 

Time: O(N*log(10^9)) ~ O(31*N)
*/
