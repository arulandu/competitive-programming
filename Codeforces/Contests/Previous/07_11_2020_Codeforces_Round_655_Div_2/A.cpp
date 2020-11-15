#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int t;

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    int n[t];
    for (int i = 0; i < t; i++){
        cin >> n[i];
    }

    for(int i = 0; i < t; i++){
        for(int j = 0; j < n[i]; j++){
            cout << 1 << " ";
        }
        cout << "\n";
    }


}

