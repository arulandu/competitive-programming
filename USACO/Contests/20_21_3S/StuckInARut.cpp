#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// stores cow data
struct Cow {
    ll x, y;
    int i; // index
};

const int MAXN = 1000;
int N;

vector<Cow> ncows (MAXN); // north cows
vector<Cow> ecows (MAXN); // east cows

// O(N^2)
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // read input into ncows and ecows accordingly
    cin >> N;
    for(int i = 0; i < N; i++){
        char d;
        cin >> d;
        if(d=='E'){
            cin >> ecows[i].x >> ecows[i].y;
            ecows[i].i = i;
        } else {
            cin >> ncows[i].x >> ncows[i].y;
            ncows[i].i = i;
        }
    }
    
    // sort north-facing cows by ascending x
    sort(ncows.begin(), ncows.begin() + N, [](const Cow& c1, const Cow& c2){
        return c1.x < c2.x;
    });

    // sort east-facing cows by ascending y
    sort(ecows.begin(), ecows.begin()+N, [](const Cow& c1, const Cow& c2){
        return c1.y < c2.y;
    });

    bool stopped[N];
    int blame[N];
    fill(stopped, stopped+N, false);
    fill(blame, blame+N, 0);

    for(auto e : ecows){
        for(auto n : ncows){
            // if cows intersect
            if(!stopped[e.i] && !stopped[n.i] && e.x < n.x && e.y > n.y){
                ll xd = n.x - e.x;
                ll yd = e.y - n.y;
                if(xd > yd){
                    // e is stopped by n
                    stopped[e.i] = true;
                    blame[n.i] += blame[e.i] + 1;
                } else if(xd < yd) {
                    // n is stopped by e
                    stopped[n.i] = true;
                    blame[e.i] += blame[n.i] + 1;
                } else {
                    // continue moving - intersect at same times
                }
            }
        }
    }

    // print out blames
    for(int i = 0; i < N; i++){
        cout << blame[i] << '\n';
    }

    return 0;
}
