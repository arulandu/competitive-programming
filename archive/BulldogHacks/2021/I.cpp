#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ps push
#define in insert
#define f first
#define s second
#define nl cout<<"\n"
#define ca(v) for(auto i:v) cout<<i<<" ";
#define cp(v) for(auto i:v) cout<<i.f<<" "<<i.s<<"\n";
#define cg(g) for(auto v:g) { ca(v); nl; }
#define cbit(x) __builtin_popcount(x)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b/gcd(a, b))
int xm[4] = {-1, 1, 0, 0};
int ym[4] = {0, 0, -1, 1};
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
const ll POW = 9973;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    queue<pair<int, int>> q;
    pair<int, int> start;
    int grid[n][m];
    vector<vector<int>> best(n, vector<int>(m, n*m + 1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin>>c;
            grid[i][j] = (c != '#');
            if(c == 'P') {
                q.ps({i, j});
                best[i][j] = 0;
            }
            if(c == 'B') start = {i, j};
        }
    }
    while(q.size()){
        auto c = q.front(); q.pop();
        int nc = best[c.f][c.s] + 1;
        for(int i=0; i<4; i++){
            int nx = c.f + xm[i];
            int ny = c.s + ym[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]&&best[nx][ny]>nc){
                best[nx][ny] = nc;
                q.ps({nx, ny});
            }
        }
    }
    vector<vector<int>> dst(n, vector<int>(m, n*m + 1));
    map<pair<int, int>, pair<int, int>> prev;
    prev[start] = {-1, -1};
    dst[start.f][start.s] = 0;
    q.ps(start);
    pair<int, int> exit = {-1, -1};
    while(q.size()){
        auto c = q.front(); q.pop();
        if(c.f==0||c.f==n-1||c.s==0||c.s==m-1){
            exit = c;
            break;
        }
        int nc = dst[c.f][c.s] + 1;
        for(int i=0; i<4; i++){
            int nx = c.f + xm[i];
            int ny = c.s + ym[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]&&dst[nx][ny]>nc&&nc<best[nx][ny]){
                prev[{nx, ny}] = c;
                dst[nx][ny] = nc;
                q.ps({nx, ny});
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<best[i][j]<<"\t";
        }nl;
    }
    if(exit.f == -1) cout<<"NO";
    else{
        vector<char> ans;
        while(exit != start){
            if(exit.f == prev[exit].f + 1) ans.pb('S');
            if(exit.f == prev[exit].f - 1) ans.pb('N');
            if(exit.s == prev[exit].s + 1) ans.pb('E');
            if(exit.s == prev[exit].s - 1) ans.pb('W');
            exit = prev[exit];
        }
        reverse(all(ans));
        cout<<"YES\n";
        for(char c:ans) cout<<c;
    }

}

//poaching