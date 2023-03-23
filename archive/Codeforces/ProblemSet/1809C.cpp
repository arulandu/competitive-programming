/*
Contest: Educational Codeforces Round 145 
Problem: [C] Sum on Subarrays
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int h(int n)
{
  return n * (n + 1) / 2;
}

int f(int n)
{
  int l = 0;
  int r = 1e4;
  while (l < r)
  {
    int m = (l + r + 1) / 2;
    if (h(m) > n)
    {
      r = m - 1;
    }
    else
    {
      l = m;
    }
  }

  return l;
}

const int MAX = 1000;

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n, 0);

  int a = f(k);
  
  for(int j = 0; j < n; j++){
    if(j < a){
      v[j] = 2;
    } else if(j == a){
      k -= a*(a+1)/2;
      v[j] = -(2*(a-k)+1);
    } else {
      v[j] = -MAX;
    }
  }

  for(auto x : v) cout << x << ' '; cout << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
