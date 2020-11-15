#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;


vector<vector<bool>> grid;
int c;
int s;
int n;

// no opt: 153745
// initial symmetry: 76872 (50% red)
// return when end square is hit: 45055
// 2 section div opt:  3979


void search(int row, int col, int f){
    s++;
    // fill position
    grid.at(row).at(col) = true;
    f++;

    // base case
    // if(row == n - 1 && col == n - 1 && f == n*n){
    //     c++;
    //     return;
    // }
    
    if(row == n - 1 && col == n - 1){
        c += (f == n*n) ? 1 : 0;
        return;
    }

    vector<vector<bool>> temp = grid;

    /*MAIN ALGORITHM*/
    bool l = col > 0 && !grid.at(row).at(col - 1);
    bool r = col < n - 1 && !grid.at(row).at(col + 1);
    bool u = row > 0 && !grid.at(row - 1).at(col);
    bool d = row < n - 1 && !grid.at(row + 1).at(col);

    // 2 sections opt
    if((!u && !d && l && r) || (!l && !r && u && d)){
        return;
    }

    // left
    if(l){
        search(row, col - 1, f);
    }
    grid = temp;

    // right
    if(r){
        search(row, col + 1, f);
    }
    grid = temp;

    // up
    if(u){
        search(row - 1, col, f);
    }
    grid = temp;

    // down
    if(d){
        search(row + 1, col, f);
    }
    grid = temp;
}

void printGrid(){
    for(auto row : grid){
        string output = "";
        for(auto cel : row){
            output += cel ? "true" : "false";
            output += "\t";
        }
        cout << output << "\n";
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cout << boolalpha;

    cin >> n;
    for(int i = 0; i < n; i++){
        vector<bool> x (n);
        fill(x.begin(), x.end(), false);
        grid.push_back(x);
    }

    printGrid();

    c = 0;
    s = 0;
    
    /* reg
    search(0, 0, 0);
    */

    grid.at(0).at(0) = true;
    search(1, 0, 1);

    cout << "count: " << 2*c << '\n';
    cout << "calls: " << s;
}