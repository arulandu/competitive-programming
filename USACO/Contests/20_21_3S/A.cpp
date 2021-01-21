#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Cow {
    ll x, y;
    char dir;
};

int N;
int main(){
    cin >> N;
    vector<Cow> cows (N), ver(N), hor(N);

    for(int i = 0; i < N; i++){
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
    }

    ver = cows; sort(ver.begin(), ver.end());
    hor = cows; sort(hor.begin(), hor.end());

    cout << "ver\n";
    for(Cow c : ver){
        cout << c.x << ", " << c.y << '\n';
    }
    cout << "hor\n";
    for(Cow c : ver){
        cout << c.x << ", " << c.y << '\n';
    }

    return 0;
}

/*
Figure out who directly blocked who
Use dfs to sum blames
*/
