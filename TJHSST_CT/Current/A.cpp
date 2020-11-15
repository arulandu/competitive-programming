#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int ar[n];
  for(int i = 0; i < n; i++){
    cin >> ar[i];
  }
  sort(ar, ar+n);

  int l = 0;
  int r = 0;

  int s = 0;
  int c = ar[n-1]-ar[0]-17;

  // cout << "l: " << l << "r: " << r << "s: " << s << "c: " << c << " end\n";

  if(c <= 0){
    goto skip;
  }

  while(l < n/2 && r < n/2){
    // cout << "l: " << l << "r: " << r << "s: " << s << "c: " << c << " end\n";

    int ldiff = ar[l+1]-ar[l];
    int rdiff = ar[n-r-1]-ar[n-r-2];
    l++;
    r++;

    // cout << "ldiff: " << ldiff << " rdiff: " << rdiff << " end\n";

    if (c <= ldiff + rdiff) {
      // cout << "bdiff\n";
      if(c % 2 == 0){
        s += (l+r)*pow(c/2, 2);
      } else {
        s += l*pow(c/2 + 1, 2) + r*pow(c/2, 2);
      }
      goto skip;
    } else {
      // cout << "ndiff\n";
     c -= ldiff+rdiff;
     s += l*pow(ldiff, 2) + r*pow(rdiff, 2);
   }

  }
  skip:;
  cout << s << '\n';

  return 0;
}

/*
17

1, 5, 7, 8, 10, 12, 13, 25

25-1=24
24-17=7=c

5-1 + 25-13 = 16 > 7
3^2 + 4^2 = 25

1, 2, 3, 8, 10, 21, 22, 25

25-1=24
24-17=7=c

1+3 = 4 < 7
s += 1^2 + 3^2

1+1 = 2 < 3
s += 2*1^2 + 2*1^2

1 2 10 22 23
s = 2
2 2 10 22 22
4 4 10 21 21
s += 2^2 + 2^2 + 1^2 + 1^2 = 12
*/
