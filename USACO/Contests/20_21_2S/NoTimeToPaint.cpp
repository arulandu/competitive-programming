#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int N, Q, pref_c[MAXN+1], suff_c[MAXN+1];
string str;

// update brush stroke array for all starting values
void compute(int *sol){
    // maintains the current colors 
    stack<char> curr;

    // go through all possible starting points
    for(int i = 0; i < N; i++){
        sol[i+1] = sol[i];

        // pop all elements larger than current element from stack
        while(!curr.empty() && curr.top() > str[i]){
            curr.pop();
        }
        
        // push element if possible and increment count
        if(curr.empty() || curr.top() < str[i]){
            curr.push(str[i]);
            sol[i+1]++;
        }
    }
}

// O(2*N+Q) => O(N+Q)
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> Q >> str;
    int a, b;

    // compute prush strokes for prefixes and suffixes
    compute(pref_c);
    reverse(str.begin(), str.end());
    compute(suff_c);

    // print appropriate sums of prefix and suffix counts
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        cout << pref_c[a-1] + suff_c[N-b] << '\n';
    }
    return 0;
}