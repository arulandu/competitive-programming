// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// struct BIT2D {
//   vector<vector<ll>> s;
//   int n, m;

//   public:
//   BIT2D(int N, int M): s(N+1, vector<ll>(M+1)), n{N}, m{M}{}

//   int lsb(int x) { return x & -x; }
//   // update index i
//   void update(int i, int delta){
//     for(++i; i < s.size(); i += lsb(i)) s[i] += delta;
//   }

//   // sum range [0, i]
//   ll query(int i) {
//     ll sum = 0;
//     for(++i; i > 0; i -= lsb(i)) sum += s[i];
//     return sum;
//   }
// };