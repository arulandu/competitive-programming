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
#define cbit(x) builtin_popcount(x)
#define gcd(a, b) gcd(a, b)
#define lcm(a, b) (a*b/gcd(a, b))
int xm[4] = {-1, 1, 0, 0};
int ym[4] = {0, 0, -1, 1};
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
const ll POW = 9973;

set<int> adj[10005];
vector<pair<int, int>> y[10005];
int vis[10005];
bool pathExists(int w, int h, vector<vector<int>> &ar){
    set<int> col;
    set<int> hs;
    int n = ar.size();
    for(int i=0; i<n; i++){
        y[ar[i][1]].pb({ar[i][0], ar[i][2]});
        col.in((ar[i][2]));
        hs.in(ar[i][1]);
    }
    for(int i:hs){
        if(y[i].size() <= 1) continue;
        sort(all(y[i]));
        for(int j=0; j<y[i].size()-1; j++){
            adj[y[i][j].s].in(y[i][j+1].s);
        }
    }
    queue<int> q;
    for(int i=0; i<y[0].size(); i++) {
        if(vis[y[0][i].s]) continue;
        vis[y[0][i].s] = 1;
        q.push(y[0][i].s);
    }
    while(q.size()){
        int c = q.front();
        q.pop();
        for(int i:adj[c]){
            if(vis[i]) continue;
            vis[i] = 1;
            q.push(i);
        }
    }
    bool ans = 0;
    for(auto p:y[h-1]){
        if(vis[p.s] == 1) ans = 1;
    }
    for(int i:hs) {
        y[i].clear();
    }
    for(int i:col){
        vis[i] = 0;
        adj[i].clear();
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
    int w, h; cin>>w>>h;
    int n; cin>>n;
    vector<vector<int>> ar(n, vector<int>(3));
    for(int i=0; i<n; i++){
        cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
    }
    cout<<pathExists(w, h, ar);
    }
}