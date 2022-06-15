/*
Contest: Codechef Starters 43
Problem: [B] The Optimal Pairs
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

template<typename T>
vector<pair<T, int>> factor(T n){
  vector<pair<T, int>> f;
  for(int i = 2; i*i <= n; i++) {
    int t = 0;
    while(n%i == 0){ n /= i; t++; }
    if(t > 0) f.push_back({i, t}); 
  }
  if(n > 1) f.push_back({n, 1});
  return f; 
}

/*
Observation: minimum of g(a, b) = N.
gcd + lcm = gcd(a, N-a)+a*(N-a)/gcd(a, N-a) = N
=> gcd(a, N-a) = a or N-a
= a and = N-a are symmetric.
gcd(a, N-a) = a => a | N and a < N. 
There exist f(N)-1 such a where f(N) is the number of factors of N.
If N is even, a = N/2 is overcounted. So,
Ans = 2(f(N)-1)-(1 ? N % 2 == 0 : 0)
where f(N) = product of (e_i+1) where e_i is the exponent of the ith prime factor
*/

void solve(){
  ll n; cin >> n;
  auto fcts = factor(n);
  ll h = 1LL; for(auto fct : fcts) h *= (fct.second+1); // # factors of N

  // formula
  h = (h-1)*2LL; if(n%2LL == 0LL) h--;
  cout << h << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
