
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, ll> euclid(ll a, ll b){
  if(!b) return {1, 0};
  auto p = euclid(b, a%b); return {p.second, p.first-a/b*p.second};
}

ll gcd(ll a, ll b){
  auto p = euclid(a, b);
  return p.first*a+p.second*b;
}

ll inv(ll a, ll b){
  auto p = euclid(a, b);
  return p.first + (p.first < 0 ? b : 0);
}

struct mint {
  ll mod;
	ll v; explicit operator ll() const { return v; } // explicit -> don't silently convert to int
	mint(ll m):mod(m), v(0) {}
	mint(ll m, ll _v):mod(m) {
    v = (ll) ((-mod < _v && _v < mod) ? _v : _v % mod);
		if (v < 0) v += mod;
  }

  mint& operator=(mint o){
    mod = o.mod; v = o.v;
    return *this;
  }

	bool operator==(const mint& o) const {
		return v == o.v;
  }
	
  friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b);
  }
	
  friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v;
  }

  friend ostream& operator<< (ostream& os, const mint& a){
    os << a.v; return os;
  }

  friend istream& operator>> (istream& is, mint& a){
    is >> a.v; return is;
  }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= mod) v -= mod; 
		return *this;
  }

	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += mod; 
		return *this;
  }

	mint& operator*=(const mint& o) { 
		v = (ll) ((ll)v*o.v%mod); return *this;
  }

	mint& operator/=(const mint& o) {
    return (*this) *= inv(o);
  }

  // binary exponentiation
	friend mint pow(mint a, ll p) {
		mint ans(a.mod, 1); assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
 		return ans;
  }

	friend mint inv(const mint& a) {
    return mint(a.mod, inv(a.v, a.mod));
  }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

void solve(ll mod){
  ll x, y; char op;
  cin >> x >> op >> y;

  mint xm(mod, x), ym(mod, y), ans(mod);

  if(op == '+'){
    ans = xm+ym;
  } else if(op == '-'){
    ans = xm-ym;
  } else if(op == '/'){
    if(gcd(ym.v, mod) != 1){
      cout << -1 << '\n'; return;
    } else {
      ans = xm/ym;
    }
  } else if(op == '*'){
    ans = xm*ym;
  }
  
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  while(true){
    ll n, t; cin >> n >> t;
    if(n == 0 && t == 0) break;
    while(t--){
      solve(n);
    }
  }

  return 0;
}
