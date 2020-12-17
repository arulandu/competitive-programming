#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

// method to handle reading and writing to file
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

// sorts in desc. by second element in pair
bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2){
  if(p1.second == p2.second){
    return p1.first < p2.first;
  } else {
    return p1.second > p2.second;
  }
}

int main(){
  handle_io(true, "rental");

  // reads in input
  ll N, M, R;
  cin >> N >> M >> R;

  ll c[N]; // production
  vector<pair<ll, ll>> m(M); // shops
  ll tR = max(N, R);
  ll r[tR]; // rentals

  // read production
  for(ll i = 0; i < N; i++){
    cin >> c[i];
  }

  // read shops
  for(ll i = 0; i < M; i++){
    cin >> m[i].first >> m[i].second;
  }

  // read rentals
  for(ll i = 0; i < tR; i++){
    if(i < R){
      cin >> r[i];
    } else {
      r[i]=0; // fill r to at least size of N
    }
  }

  // sort
  sort(c, c+N, greater<ll>()); // sort production desc.
  sort(m.begin(), m.end(), cmp); // sort shops desc in price
  sort(r, r+tR); // sort rental ascending

  ll fp[N+1]; // prefix sums - fp[i] is the money made milking the i largest producers
  fp[0] = 0;
  ll j = 0;
  for(ll i = 1; i <= N; i++){
    ll g = c[i-1];
    if(i == 0){
      fp[i] = 0;
    } else {
      fp[i] = fp[i-1];
    }

    // simulate through selling milk for the highest price always
    while(j < M){
      ll x = min(m[j].first, g);
      g -= x;
      m[j].first -= x;
      fp[i]+=x*m[j].second;
      if(g > 0){
        j++;
      } else {
        break;
      }
    }
  }

  ll gp[N+1]; // prefix sums - g[i] is the money made milking the i smallest producers
  gp[0] = 0;
  ll startR = max(R-N-1, (ll)-1); // handles case where R > N
  for(ll i = 1; i <= N; i++){
    if(i == 1){
      gp[i]=0;
    } else {
      gp[i]=gp[i-1];
    }
    gp[i]+=r[startR+i];
  }

  ll mx = gp[N]; // stores max value

  // calculate maximum of milking largest i producers and renting the rest
  for(ll i = 0; i <= N; i++){
    ll v = fp[i] + gp[N] - gp[i];
    mx = max(mx, v);
  }

  // print answer
  cout << mx << '\n';

  return 0;
}
