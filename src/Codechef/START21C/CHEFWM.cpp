/*
Contest: CodeChef Starters 21 Division 3
Problem: [E] ChefWM
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// prime factorization
vector<ll> prime(ll n) { 
  vector<ll> fcts;
  while (n % 2 == 0) { 
    fcts.push_back(2);
    n = n/2; 
  } 

  for (ll i = 3; i <= sqrt(n); i = i + 2) { 
    while (n % i == 0) { 
        fcts.push_back(i);
        n = n/i; 
    } 
  } 

  if (n > 2) fcts.push_back(n);

  return fcts;
} 

ll solve(){
  ll n, m; cin >> n >> m;

  // find largest factor of n <= # of distinct prime factors of m
  vector<ll> pm = prime(m);
  set<ll> pms; for(auto x : pm) if(!pms.count(x)) pms.insert(x);
  for(ll i = pms.size(); i >= 1; i--) if(n%i == 0) return i;

  return 0;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) cout << solve() << '\n';

  return 0;
}
