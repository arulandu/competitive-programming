#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool debug = false;
void handle_io(bool end, string filename=""){
  if(end){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }

  if(filename.length() > 0){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
}

const int MAXN = 1e5;
const int MAXM = 1e5;
const ll MAXW = 1e9;
int N, M;

// stores wormhole data
struct Hole {
    int a, b;
    ll w;
};

int p[MAXN]; // stores starting location of cows
vector<vector<pair<int, ll>>> adj(MAXN); // stores graph
vector<int> component(MAXN); // stores component label for each node
vector<Hole> holes(MAXM); // stores wormholes

// dfs updating component label
void dfs(int a, int cl, ll minw){
    component[a] = cl; // update label

    // recur to unlabeled children with valid width
    for(auto c : adj[a]){
        if(component[c.first] == -1 && c.second >= minw){
            dfs(c.first, cl, minw);
        }
    }
}

// check if every cow is in same component as desired location using only wormholes >= minw
bool validate(ll minw){
    fill(component.begin(), component.end(), -1);

    // dfs and update component label of each node
    int cl = -1;
    for(int i = 0; i < N; i++){
        if(component[i] == -1){
            dfs(i, ++cl, minw);
        }
    }

    // check if all cows have same component as destination and return accordingly
    for(int i = 0; i < N; i++){
        if(component[p[i]] != component[i+1]){
            return false;
        }
    }

    return true;
}

// O((M+N)*log(M))
int main(){
    handle_io(true, "wormsort");

    // read cow position input
    cin >> N >> M;
    bool preSorted = true;
    for(int i = 0; i < N; i++){
        cin >> p[i];
        if(i+1 != p[i]){
            preSorted = false;
        }
    }

    // end if already sorted
    if(preSorted){
        cout << -1 << '\n';
        return 0;
    }

    // read in wormholes
    for(int i = 0; i < M; i++){
        cin >> holes[i].a >> holes[i].b >> holes[i].w;
    }

    // sort wormholes descending by width
    sort(holes.begin(), holes.begin()+M, [](const Hole &h1, const Hole &h2){
        return h1.w > h2.w;
    });

    // make graph with wormholes as edges
    for(int i = 0; i < M; i++){
        adj[holes[i].a].push_back(make_pair(holes[i].b, holes[i].w));
        adj[holes[i].b].push_back(make_pair(holes[i].a, holes[i].w));
    }

    // binary search on answer - using the wormhole index
    int l = 0;
    int r = M-1;
    while(l <= r){
        int m = (l+r)/2;
        if(validate(holes[m].w)){
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << holes[l].w << '\n';
    
    return 0;
}