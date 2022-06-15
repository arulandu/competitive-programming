#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

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

bool isUnique(ll p){
  if(to_string(p).length() > 10){
    return false;
  }
  ll x = p;
  bool visited[10]={false};
  while(x!=0){
    if(visited[x%10]){
      break;
    }
    visited[x%10]=true;
    x/=10;
  }

  return x==0;
}

bool isPrime(ll p){
  if(p % 2==0){
    return p==2? true : false;
  }

  for(ll i = 3; i*i < p; i+=2){
    if(p % i == 0){
      return false;
    }
  }

  return true;
}

int main(){
  handle_io(false);

  string nf = "Brice doesn't stand a chance!";
  ll t;
  int ans1[] = {2, 3, 5};

  while(t--){
    int d, x;
    cin >> d >> x;
    if(d>10){
      cout << nf;
    }

    if(d==1){
      if(x > 3){
        cout << nf;
      } else {
        cout << ans1[x-1];
      }
    }

    ll lb = 1;
    for(int i = 0; i < d-1; i++){
      lb *= 10;
    }

    cout << "debug\n";
    int c = 1;
    cout << lb << ' ';
    for(ll i = lb; i < lb*10; i++){
      if(isPrime(i) && isPrime(i+2) && isUnique(i)){
        cout << i << '\n';
        if(c==x){
          cout << i;
          goto skip;
        } else {
          c++;
        }
      }
    }
    cout << nf;
    skip:;
    cout << '\n';
  }

  return 0;
}

/*
2
2 3
1 9
*/
