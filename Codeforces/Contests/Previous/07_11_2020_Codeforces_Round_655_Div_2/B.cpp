#include <iostream>

using namespace std;

typedef long long ll;

int lcm(int a, int b){
    int max = (a > b) ? a : b;

    do
    {
        if (max % a == 0 && max % b == 0)
        {
            return max;
            break;
        }
        else
            ++max;
    } while (true);

    return -1;
}

int main()
{
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    int n[t];
    for (int i = 0; i < t; i++){
        cin >> n[i];
    }

    
    for(int i = 0; i < t; i++){
        int lcl = INT16_MAX;
        int al = -1;
        for(int a = 1; a < n[i]; a++){
            int l = lcm(a, n[i] - a);
            if(l < lcl){
                lcl = l;
                al = a;
            }
        }
        cout << al << " " << n[i] - al << "\n";
    }
}

