/**
 * Description: Tests primality / find smallest prime up to N. Optimize by only storing odd indices.
 * Complexity: O(n*log(log(n))) ~ O(n)
 * Source: KACTL / CPH https://usaco.guide/CPH.pdf#page=210
 * Verification: https://open.kattis.com/problems/primesieve
 */

#include <bits/stdc++.h>

using namespace std;
#define ll long long

template<int N>
struct Sieve {
  bitset<N> is_prime; vector<int> primes;
  Sieve() {
    is_prime.set(); is_prime[0] = is_prime[1] = 0;
    for(int i = 4; i < N; i += 2) is_prime[i] = 0;

    for(int i = 3; i*i < N; i += 2){
      if(is_prime[i]){
        for(int j = i*i; j < N; j += i*2) is_prime[j] = 0;
      }
    }

    for(int i = 0; i < N; i++) if(is_prime[i]) primes.push_back(i);
  }

  int sp[SZ]{}; // smallest prime that divides
  Sieve() {
    for(int x = 2; x <= N; x++){
      if(sp[i] == 0) {
        sp[i] = i; primes.push_back(i);
      }
      for(int p: primes) {
        if(p > sp[i] || i*p >= N) break;
        sp[i*p] = p;
      }
    }
  }
};