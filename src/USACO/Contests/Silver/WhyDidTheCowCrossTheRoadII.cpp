#include <bits/stdc++.h>

using namespace std;
#define ll long long

void handle_io(bool end, string filename = "")
{
  if (end)
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if (filename.length() > 0)
  {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
  }
}

int main()
{
  // handle_io(false);
  handle_io(true, "maxcross");

  int n, k, b;
  cin >> n >> k >> b;
  vector<int> s(n, 1);
  for (int i = 0; i < b; i++)
  {
    int r;
    cin >> r;
    s[r - 1] = 0;
  }

  vector<int> pf(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 0)
      pf[i]++;
    if (i > 0)
      pf[i] += pf[i - 1];
  }

  int m = INT_MAX;
  for (int i = 0; i <= n - k; i++)
  {
    m = min(pf[i + k - 1] - (i > 0 ? pf[i - 1] : 0), m);
  }

  cout << m << '\n';
}
