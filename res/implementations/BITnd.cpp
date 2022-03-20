
/**
 * Description: range sum queries and point updates for $D$ dimensions
 * Source: https://codeforces.com/blog/entry/64914
 * Usage: \texttt{BIT<int,10,10>} gives 2D BIT
 * Time: O((\log N)^D)
 */

template <class T, int... ArgsT> struct BIT {
  T val = 0;
  
  void update(T v) {
    val += v;
  }
  
  T query() {
    return val;
  }
};

template <class T, int N, int... Ns>
struct BIT<T, N, Ns...> {
  BIT<T, Ns...> bit[N+1];

  template<typename... Args>
  void update(int pos, Args... args) {
    for (; pos <= N; pos += lsb(pos)) bit[pos].update(args...);
  }

  template<typename... Args>
  T sum(int r, Args... args) {
    T res = 0;
    for(; r >= 1; r -= lsb(r)) res += bit[r].query(args...);
    return res;
  }

  template<typename... Args>
  T query(int l, int r, Args... args) {
    return sum(r, args...) - sum(l-1, args...);
  }

  int lsb(int v){
    return v & (-v);
  }
};
