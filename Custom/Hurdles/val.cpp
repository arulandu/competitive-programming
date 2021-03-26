#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 100000, "n");
    for(int i = 0; i < n; i++){
        inf.readDouble(0,1000.);
        inf.readSpace();
        inf.readDouble(0,1000.);
        inf.readEoln();
    }

    inf.readEof();
}