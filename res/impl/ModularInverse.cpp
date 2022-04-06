#include "cp_algos.h"
#include <iostream>
using namespace std;
// calculates inverse of a mod p | p is a prime. 
int inverseModP(int a, int p){
    if(a%p==0){
        return -1;
    }
    return binaryExpModM(a, p-2, p); // fermat's little theorem
}