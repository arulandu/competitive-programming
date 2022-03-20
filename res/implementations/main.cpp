#include <iostream>
#include "cp_algos.h"
using namespace std;

int main(){
    // command line tool
    int a, b;
    while(true){
        cout << "> ";
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        cout << inverseModP(a, b) << '\n';
    }
    cout << "exited\n";
    return 0;
}