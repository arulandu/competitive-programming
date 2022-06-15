#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7};
vector<int> p1;
vector<int> p2;

int main(){
    for(int i = 0; i < sizeof(arr); i++){
        if(i < sizeof(arr) / 2){
            p1.push_back(arr[i]);
        } else {
            p2.push_back(arr[i]);
        }
    }
    return 0;
}