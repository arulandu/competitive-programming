#include <iostream>
using namespace std;
#include "cp_algos.h"

int binaryExp(int a, int b){
    int r = 1;
    // go through each bit of b
    while(b > 0){
        if(b%2==1){
            r *= a; // multiply result with corresponding power of a if bit is 1
        }
        a *= a;
        b /= 2;
    }
    return r;
}

int binaryExpModM(int a, int b, int m){
    long long r = 1;
    // go through each bit of b
    while(b > 0){
        if(b%2==1){
            r = (r*a)%m; // multiply result with corresponding power of a if bit is 1
        }
        a = (a*a)%m;
        b /= 2;
    }
    return r;
}