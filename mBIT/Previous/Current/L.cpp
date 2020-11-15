#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define re reverse
#define ps push
#define in insert
#define fr front
#define f first
#define s second
#define sv(v) shuffle(all(v), default_random_engine())
#define sa(a, n) shuffle(a, a+n, default_random_engine())
#define ca(v) for(auto i:v) cout<<i<<" ";
#define nl cout<<"\n"
#define del(s, x) s.erase(s.find(x))
#define delend(s) s.erase(--s.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b/gcd(a, b))
#define debug cout<<"DEBUG\n"
int xm[4] = {-1, 1, 0, 0};
int ym[4] = {0, 0, -1, 1};
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
bool checkbound(int n, int m, int x, int y, int i){
    if(x+xm[i]<n&&y+ym[i]<m&&x+xm[i]>=0&&y+ym[i]>=0) return true;
    return false;
}
int checked[1005][1005];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int grid[n][n];
    int groups[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int flg = 1;
            for(int k=0; k<4; k++){
                if(checkbound(n, n, i, j, k)){
                    if(grid[i+xm[k]][j+xm[k]]<grid[i][j]) flg = 0;
                }
                else flg = 0;
            }
            groups[i][j] = flg;
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(groups[i][j]==0) checked[i][j] = 1;
            else{
                if(!checked[i][j]){
                    cnt++;
                    queue<pair<int, int>> q;
                    while(q.size()>0){
                        auto cur = q.front();
                        q.pop();
                        for(int k=0; k<4; k++){
                            if(grid[cur.f+xm[k]][cur.s+ym[k]]==1 && checked[cur.f+xm[k]][cur.s+ym[k]]==0){
                                checked[cur.f+xm[k]][cur.s+ym[k]] = 1;
                                q.ps(mp(cur.f+xm[k],cur.s+ym[k]));
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<"\n";
}
