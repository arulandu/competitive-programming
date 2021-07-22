#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

struct DSU {
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent = vector<int>(n, -1);
        size = vector<int>(n, 0);
    }

    void make_set(int v){
        if(v < 0 || size[v] > 0){
            return;
        }
    
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v){
        if(parent[v] == -1){
            return -1;
        }

        if(v == parent[v])
            return v;

        int p = find_set(parent[v]);
        parent[v] = p; // path compression
        return p;
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            // union by size
            if(size[a] < size[b]){
                parent[a] = b;
                size[b] += size[a];
            } else {
                parent[b] = a;
                size[a] += size[b];
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    DSU dsu(n+1);

    for(int i = 0; i < m; i++){
        int k; cin >> k;
        if(k <= 0) continue;

        // create sets and union in order
        int p, x; cin >> p;
        dsu.make_set(p);
        for(int j = 1; j < k; j++){
            int x; cin >> x;
            dsu.make_set(x);
            dsu.union_sets(p, x);
            p = x;
        }
    }

    // get representative size
    for(int i = 1; i <= n; i++){
        int pi = dsu.find_set(i);
        cout << (pi == -1 ? 1 : dsu.size[pi]) << ' ';
    }
    cout << '\n';

    return 0;
}
