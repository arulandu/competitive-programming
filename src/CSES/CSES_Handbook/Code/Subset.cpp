#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 5;
    cout << boolalpha;

    for(int b = 0; b < (1<<n); b++){
        vector<int> subset;
        for(int i = 0; i < n; i++){
            if(b&(1<<i)){
                subset.push_back(i);
            }
        }

        for(auto i : subset){
            cout << i << ' ';
        }

        cout << "ss\n";
    }
    
    return 0;
}