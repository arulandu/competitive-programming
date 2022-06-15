/*
Contest: Codeforces Round #756 (Div. 3)
Problem: [F] ATM and Students
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXN = 2e5;
int n; ll s;
vector<ll> a(MAXN);
vector<ll> pf(MAXN);

// find first index that is the start of a valid length = ln subarray
int f(int ln){
  if(ln == 0) return 0; // allow ln = 0 and catch invalidity later

  // maintain sliding window set of prefix sums
  multiset<ll> pfs;
  for(int i = 0; i < ln; i++) pfs.insert(pf[i]);

  for(int i = 0; i < n-ln+1; i++){
    // check if lowest element in set is still valid
    if(*pfs.begin()-(i>0 ? pf[i-1] : 0) >= -s) return i;

    if(i < n-ln){
      pfs.erase(pfs.find(pf[i]));
      pfs.insert(pf[i+ln]);
    }
  }

  return -1;
}

void solve(){
  // prefix sum
  cin >> n >> s;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) pf[i] = a[i]+(i > 0 ? pf[i-1] : 0);
  
  // binary search on length of subarray
  int lb = 0, ub = n;
  while(lb < ub){
    int md = (lb+ub+1)/2;
    if(f(md) != -1){
      lb = md;
    } else {
      ub = md-1;
    }
  }

  // print subsequence
  if(lb == 0) { cout << -1 << '\n'; return; }
  int st = f(lb); cout << st+1 << ' ' << st+lb << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
/*
NOTE: This can also be done with two pointers in O(n)
1. Intialize sum to the given value.
2. Maintain the l, r and keep track of sum of subarray at all times.
3. If the sum is negative move l until the sum is positive. 
4. If the sum is positive, update max.
5. Move r and repeat 2-4 until out of bounds
*/
