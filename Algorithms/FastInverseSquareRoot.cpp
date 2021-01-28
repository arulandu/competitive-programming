#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float isqrt(float n){
    long i;
    float x2, y;
    const float threehalves = 1.5F;
    x2 = n*0.5F;
    y = n;

    // convert float to long without changing bits
    i = *(long*) &y;

    // bit shift with correction term
    i = 0x5f3759df - (i >> 1);

    // convert long back to float without changing bits
    y = *(float*) &i;

    // newton's method to find zero of f(y) = (1/y^2) - x
    y = y * (threehalves - (x2*y*y));
    y = y * (threehalves - (x2*y*y));

    return y;
} 

int main(){
    // command line tool
    float n;
    while(true){
        cout << "> ";
        cin >> n;
        if(n == 0){
            break;
        }
        cout << isqrt(n) << '\n';
    }
    cout << "exited\n";
    return 0;
}