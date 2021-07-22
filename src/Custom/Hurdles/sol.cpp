#include<bits/stdc++.h>
#include<iostream>
typedef long long ll;
typedef long double ld;
using namespace std;

const ld PI = 3.141592653589793238462643383279502884L;

struct Point {
    ld x, y, theta;
};

ld dist(Point& p1, Point& p2) {
    return sqrtl(powl(p1.x-p2.x,2)+powl(p1.y-p2.y,2));
}

int main(){
    ll n;
    cin >> n;

    vector<Point> v(n+1);
    v[0] = {1,0,0};  
    for(int i = 1; i <= n; i++){
        cin >> v[i].x >> v[i].y;
        v[i].theta = atan2l(v[i].y*1.0,v[i].x*1.0) + (v[i].y < 0 ? 2*PI : 0);
    }
    
    sort(v.begin(), v.end(), [](const Point& p1, const Point& p2){ p1.theta < p2.theta; });

    ld td = dist(v[0], v[n]);
    for(int i = 1; i <= n; i++){
        td += dist(v[i], v[i-1]);
    }
    
    cout << lroundl(td/PI) << '\n';
    return 0;
}
