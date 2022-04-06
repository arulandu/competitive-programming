#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

/*
1-783
3*(5*5) + 0-83 => 3*(5*5) + 4(5) + 1-3 => 3*(5*5)+4*(5)+2*(1)

1-779
3*(5*5) + 0-79 => 3*(5*5) + 4*(5)

# IDEA - express L and R like above, then subtract
*/

// ll count(ll b){
//   string bstr = to_string(b);
//   int len = bstr.length();
//   ll sum = 0;
//   for(int i = len - 1; i >= 0; i--){
//     int d = bstr[len-i-1]-'0';
//     int x = (d/2)*pow(5, i);
//     cout << x << ' ';
//     sum += x;
//   }
//   return sum;
// }

bool check(ll b){
  string bstr = to_string(b);
  for(int j = 0; j < bstr.length(); j++){
    int d = bstr[j] - '0';
    if(!((d % 2) == ((j+1) % 2))){
      return false;
    }
  }

  return true;
}

int main(){
  handle_io(true);

  ll t;
  cin >> t;
  for(int f = 1; f <= t; f++){
    cout << "Case #" << f << ": ";

    // TARGET COMPLEXITY: O(1)
    ll l, r;
    cin >> l >> r;
    ll c = 0;
    for(ll i = l; i <= r; i++){
      if(check(i)){
        // cout << i << ' ';
        c++;
      }
    }

    cout << c << '\n';

    // ll x;
    // cin >> x;
    // cout << (check(x) ? "true" : "false") << '\n';

  }

  return 0;
}

/*
5 - 15 => 5-9 + 10-15
5-9 => 5, 7, 9
10-15 => 1 * 3

120 - 125 => 1*1*3
779-783 -> 1*1*2

1 4
2 5
3 8
2 4
1 5



1 - 9
1, 3, 5, 7, 9
=> 1*5

10-99
10, 12, 14, 16, 18
...
90, 92, 94, 96, 98
=> 5*5

100-999
101, 103, 105, 107, 109
...
181, 183, 185, 187, 189
...
981, 983, 985, 987, 989
=> 5 * 5 * 5

100..n-1..0 - 999...n...9 => 5^n

1 - 387
1*(5*5) + 0-87
1*(5*5) + 6*(5) + 1-7
1*(5*5) + 4*(5) + 4*(1)

1-783
3*(5*5) + 0-83 => 3*(5*5) + 4(5) + 1-3 => 3*(5*5)+4*(5)+2*(1)

1-779
3*(5*5) + 0-79 => 3*(5*5) + 4*(5)

# IDEA - express L and R like above, then subtract




*/
