#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Cell {
    string c;
    int x, y;

    bool isWall(){
        return c == "###";
    }

    bool isBessie(){
        return c == "BBB";
    }

};

string toStr(const Cell& c){
    return c.c + " " + to_string(c.x) + " " + to_string(c.y);
}

const int maxN = 25;

int N;
vector<vector<Cell>> grid (maxN, vector<Cell> (maxN));
pair<int, int> st;
vector<Cell> depc;
map<Cell, vector<Cell>> dep;

void dfs(int x, int y){
    if(x < 0 || y < 0 || x > N || y > N) return;
    if(grid[y][x].isWall()) return;

    dep.insert(make_pair(grid[y][x], depc));
    depc.push_back(grid[y][x]);

    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);

    depc.pop_back();
}

int main(){
    // cin.tie();
    // ios_base::sync_with_stdio(false);

    cin >> N;
    for(int j = 0; j < N; j++){
        string s;
        cin >> s;
        for(int i = 0; i < N; i++){
            grid[j][i].c = s.substr(i*3, 3);
            if(grid[j][i].isBessie()){
                st = make_pair(i, j);
            }
        }
    }

    dfs(st.first, st.second);

    
    
    return 0;
}