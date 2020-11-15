#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[] = {1, 10, 1, 1, 2, 2, 3, 4, 5, 1, 5, 6};

    auto x = lower_bound(a, a+10, 2)-a;

    if(x < 10 && a[x]==2){
        cout << x;
    } else {
        cout << -1;
    }

}