#include <iostream>
#include <std
using namespace std;

typedef long long ll;

int t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    vector<vector<int>> ps;
    for (int i = 0; i < t; i++){
        int s;
        cin >> s;
        vector<int> n;
        for(int j = 0; j < s; j++){
            int q;
            cin >> q;
            n.push_back(q);
        }
        ps.push_back(n);
    }

    for(vector<int> p : ps){
        for (int i : p){
            cout << p << " ";
        }
        cout << "\n";
    }

    // Compare the current state with a sorted version
    // get range where the unsorted starts - 1245367 => (3, 5)
    // if range size > 0 then inc the counter and switch numbers to sorted spots - if the current state is sorted then move to the left most
    // 4 2 3 5 1 6 7
    // 2 3 4 5 1 6 7
    // 1 2 3 4 5 6 7
    // FIND standalones then +1


}

