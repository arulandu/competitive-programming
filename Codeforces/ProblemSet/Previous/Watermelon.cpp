#include <iostream>

using namespace std;

int main(){
    int x;
    cin >> x;
    cout << ((x % 2 == 0 && x > 2) ? "YES" : "NO");
    return 0;
}