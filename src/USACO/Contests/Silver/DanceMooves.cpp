#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5;
const int MAXK = 2e5;
int N, K;

vector<int> adj[MAXN];
vector<int> component(MAXN);
unordered_set<int> distinct;

// run dfs to label component
void dfs(int i, int label){
    component[i] = label;

    for(auto x : adj[i]){
        distinct.insert(x);
    }
    
    if(adj[i].size() > 0 && component[adj[i][adj[i].size()-1]] == -1){
        dfs(adj[i][adj[i].size()-1], label);
    }
}

// counts the size of a connected component
int count(int i, int label){
    distinct.clear();
    dfs(i, label);
    return distinct.size();
}

void solve(){
    // creates map of each component label and its size
    map<int, int> m;

    // clear labels
    fill(component.begin(), component.begin() + N, -1);

    // label and count components
    int label = -1;
    for(int i = 0; i < N; i++){
        if(component[i] == -1) m.insert(make_pair(label, count(i, ++label)));
    }

    // prints the size of the component each node is in
    for(int i = 0; i < N; i++){
        cout << m[component[i]] << '\n';
    }
}

int main(){
    // fast io
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // read input
    cin >> N >> K;
    int line[N];
    for(int i = 0; i < N; i++){
        line[i] = i;
    }
    vector<pair<int, int>> swaps (K);
    for(int i = 0; i < K; i++){
        cin >> swaps[i].first >> swaps[i].second;
    }

    // initialize graph
    for(int i = 0; i < N; i++){
        adj[i].push_back(i);
    }

    // do one round of swaps
    for(int i = 0; i < K; i++){
        int a = swaps[i].first -1;
        int b = swaps[i].second -1;

        // update graph
        adj[line[a]].push_back(b);
        adj[line[b]].push_back(a);

        // do swap
        int tmp = line[a];
        line[a] = line[b];
        line[b] = tmp;
    }

    solve();

    return 0;
}
