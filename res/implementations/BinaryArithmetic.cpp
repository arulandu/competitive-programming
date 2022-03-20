/*
Source: Geeks for Geeks
https://www.geeksforgeeks.org/count-numbers-up-to-n-having-kth-bit-set/
*/

typedef long long ll;

// counts # times kth bit is 1 in range [0, n)
ll cntk(ll n, int k) {
  return (n >> (k + 1)) << k + (((n >> k) & 1) ? n & ((1ll << k) - 1) : 0);
}
