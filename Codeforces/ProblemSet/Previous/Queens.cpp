#include <iostream>
#include <vector>

using namespace std;

int n;
int c;
vector<bool> col;
vector<bool> d1;
vector<bool> d2;

void search(int y){
    if (y == n){
        c++;
        return;
    }

    // moves across row
    for(int x = 0; x < n; x++){
        if (col[x] || d1[x+y] || d2[x-y+n-1]){
            continue;
        }

        col[x] = d1[x+y] = d2[x-y+n-1] = 1; // set
        search(y+1);
        col[x] = d1[x+y] = d2[x-y+n-1] = 0; // reset
    }
}

int main(){
    cin >> n;

    col.resize(n, false);
    d1.resize(2*n - 1, false);
    d2.resize(2*n - 1, false);

    search(0);

    cout << c;
}