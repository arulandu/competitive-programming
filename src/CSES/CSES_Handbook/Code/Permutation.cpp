#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a;
    int n = 3;
    for(int i = 0; i < n; i++){
        a.push_back(i);
    }

    do {
        for(auto i : a){
            cout << i << " ";
        }
        cout << "\n";
    } while(next_permutation(a.begin(), a.end()));
    
    return 0;
}