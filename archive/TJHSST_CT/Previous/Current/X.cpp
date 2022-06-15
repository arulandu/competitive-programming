#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void setIO(string name="") {
	ios_base::sync_with_stdio(0); cin.tie(0);
  if(sizeof(name) > 0){
	   freopen((name+".in").c_str(),"r",stdin);
	 freopen((name+".out").c_str(),"w",stdout);
  }
}

int main(){
  setIO();

  int n, q;
  cin >> n >> q;
  ll ar[n];
  for(int i = 0; i < n; i++){
    cin >> ar[i];
  }

  sort(ar, ar+n);
  for(int i = 0; i < q; i++){
    ll l, r;
    cin >> l >> r;
    cout << upper_bound(ar, ar+n, r) - lower_bound(ar, ar+n, l);
  }

  return 0;
}
