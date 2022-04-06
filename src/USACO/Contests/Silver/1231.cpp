#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Query {
  string q;
  int ind;
  int ans = -1;
};

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  string s, t; cin >> s >> t;
  int Q; cin >> Q;
  vector<Query> qs(Q);
  for(int q = 0; q < Q; q++) {
    qs[q].ind = q; cin >> qs[q].q; qs[q].ans = -1;
  }

  // sort(qs.begin(), qs.end(), [](const Query &q1, const Query &q2){ return q1.q < q2.q; });
  
  auto ck = [&s, &t](set<char> &key){
    string sp = "", tp = "";
    for(auto x : s) if(key.count(x) == 1) sp += x;
    for(auto x : t) if(key.count(x) == 1) tp += x;

    return sp == tp;
  };

  map<string, bool> mp;
  vector<char> sngls;
  for(char sng = 'a'; sng <= 'z'; sng++){
    set<char> st = {sng}; bool b = ck(st);
    if(b) sngls.push_back(sng);
    mp[""+sng] = b;
  }
  
  for(int i = 0; i < sngls.size(); i++){
    for(int j = i+1; j < sngls.size(); j++){
      set<char> st = {sngls[i], sngls[j]};
      string key = ""+sngls[i]; key += sngls[j];
      mp[key] = ck(st);
    }
  }

  auto eval = [&](string &q){
    if(q.size() == 1) return mp[""+q[0]];

    for(int i = 0; i < q.size(); i++){
      for(int j = i+1; j < q.size(); j++){
        string key = ""+q[i]; key += q[j];
        if(!mp[key]) return false;
      }
    }

    return true;
  };
  
  for(auto &qry : qs){
    qry.ans = int(eval(qry.q));
  }
  

  // sort(qs.begin(), qs.end(), [](const Query &q1, const Query &q2){ return q1.ind < q2.ind; });
  for(int i = 0; i < Q; i++){
    assert(i == qs[i].ind && qs[i].ans != -1);
    
    cout << (qs[i].ans == 1 ? "Y" : "N");
  }
  cout << '\n';

  return 0;
}

/*
sorted order: if query works any prefix of it must work. if prefix doesn't work break.
sort queries then eval query:
  - if query in precomputed prefixes => good
  - else iterate through prefixes of query (small to large):
    - if prefix is bad: store bad result => bad
    - if prefix is good: continue
    - if reached end: store good result => good

---

consider all pairs of letters in the alphabet (precompute). 
if each pair of letters in the query are good together, does the query work?
if one pair of letters in the query doesn't work, does the query break? yes

*/
