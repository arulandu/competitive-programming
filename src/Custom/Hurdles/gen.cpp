#include "testlib.h"
#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ll maxn = atoll(argv[1]), r = atoll(argv[2])*1., s = atoi(argv[3]);
    rnd.setSeed(s);
    
    ll n = rnd.next((ll)maxn*3/4,maxn);
    cout << n << '\n';

    set<ld> args;
    int i = 0;
    while(i < n){
        pair<ll, ll> p = make_pair(rnd.next(-r,r), rnd.next(-r,r));
        ld arg = p.first / (p.second*(1.0));
        if(args.count(arg) > 0){
            continue;
        } else {
            args.insert(arg);
            cout << p.first << ' ' << p.second << '\n';
        }
        i++;
    }
}