#include <iostream>
#include <vector>

using namespace std;

int n;
int c;

vector<vector<bool>> grid;


void printGrid(vector<vector<bool>> g){
    for(auto row : g){
        for(auto col : row){
            cout << col << "\t";
        }
        cout << "\n";
    }
}

int search(int row, int col, int f){
    //cout << 'r';
    /**/ cout << row << ", " << col << ", " << f << "\n"; 
    //printGrid(grid);
    // base
    if(row == n - 1 && col == n - 1 && f == n*n - 1) {
        cout << "sol";
        c++;
        return 0;
    }

    bool l, r, t, b;
    l = r = t = b = true;
    if(col == 0 || grid.at(row).at(col - 1)){
        l = false;
    }

    if(col == n - 1 || grid.at(row).at(col + 1)){
        r = false;
    }

    if(row == 0 || grid.at(row - 1).at(col)){
        t = false;
    }

    if(row == n - 1 || grid.at(row + 1).at(col)){
        b = false;
    }

    /**/ cout << "stat " << l << '\t' << r << '\t' << t << '\t' << b << '\n'; 

    vector<vector<bool>> tmp = grid;
    grid.at(row).at(col) = true;

    if(l){
        /**/ cout << "l \n";
        search(row, col - 1, f + 1);
        grid = tmp;
    }

    if(r){
        /**/ cout << "r \n";
        search(row, col + 1, f + 1);
        grid = tmp;
    }

    if(t){
        /**/ cout << "t \n";
        search(row - 1, col, f + 1);
        grid = tmp;
    }

    if(b){
        /**/ cout << "b \n";
        search(row + 1, col, f + 1);
        grid = tmp;
    }
    cout << "xx";
    grid = tmp;

    return 0;
}

int main(){
    

    cin >> n;
    for(int i = 0; i < n; i++){
        vector<bool> row;

        for(int j = 0; j < n; j++){
            row.push_back(false);
        }

        grid.push_back(row);
    }
    
    c = 0;
    cout << c;
    printGrid(grid);
    search(0, 0, 0);
    printGrid(grid);
    cout << "hello";
    cout << c + "";
    return 0;
}