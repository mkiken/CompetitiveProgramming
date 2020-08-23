#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef tuple<int, int, int> ituple;

// const int INF = INT_MAX;
// const ll INF = LLONG_MAX;
// const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (100000 + 2)

template<ll mod> class ModLL {
public:
	ll x;
	constexpr ModLL():x(0) {
		// do nothing
	}
	constexpr ModLL(ll y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {
		// do nothing
	}
	ModLL &operator+=(const ModLL &p) {
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModLL &operator+=(const ll y) {
		ModLL p(y);
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModLL &operator+=(const int y) {
		ModLL p(y);
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModLL &operator-=(const ModLL &p) {
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModLL &operator-=(const ll y) {
		ModLL p(y);
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModLL &operator-=(const int y) {
		ModLL p(y);
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModLL &operator*=(const ModLL &p) {
		x = (x * p.x % mod);
		return *this;
	}
	ModLL &operator*=(const ll y) {
		ModLL p(y);
		x = (x * p.x % mod);
		return *this;
	}
	ModLL &operator*=(const int y) {
		ModLL p(y);
		x = (x * p.x % mod);
		return *this;
	}
	ModLL &operator^=(const ModLL &p) {
		x = (x ^ p.x) % mod;
		return *this;
	}
	ModLL &operator^=(const ll y) {
		ModLL p(y);
		x = (x ^ p.x) % mod;
		return *this;
	}
	ModLL &operator^=(const int y) {
		ModLL p(y);
		x = (x ^ p.x) % mod;
		return *this;
	}
	ModLL &operator/=(const ModLL &p) {
		*this *= p.inv();
		return *this;
	}
	ModLL &operator/=(const ll y) {
		ModLL p(y);
		*this *= p.inv();
		return *this;
	}
	ModLL &operator/=(const int y) {
		ModLL p(y);
		*this *= p.inv();
		return *this;
	}
	ModLL operator=(const int y) {
		ModLL p(y);
		*this = p;
		return *this;
	}
	ModLL operator=(const ll y) {
		ModLL p(y);
		*this = p;
		return *this;
	}
	ModLL operator-() const { return ModLL(-x); }
	ModLL operator++() {
		x++;
		if(x>=mod) x-=mod;
		return *this;
	}
	ModLL operator--() {
		x--;
		if(x<0) x+=mod;
		return *this;
	}
	ModLL operator+(const ModLL &p) const { return ModLL(*this) += p; }
	ModLL operator-(const ModLL &p) const { return ModLL(*this) -= p; }
	ModLL operator*(const ModLL &p) const { return ModLL(*this) *= p; }
	ModLL operator/(const ModLL &p) const { return ModLL(*this) /= p; }
	ModLL operator^(const ModLL &p) const { return ModLL(*this) ^= p; }
	bool operator==(const ModLL &p) const { return x == p.x; }
	bool operator!=(const ModLL &p) const { return x != p.x; }
	ModLL inv() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while(b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModLL(u);
	}
	ModLL pow(ll n) const {
		ModLL ret(1), mul(x);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}
	friend ostream &operator<<(ostream &os, const ModLL &p) {
		return os << p.x;
	}
	friend istream &operator>>(istream &is, ModLL &a) {
		ll t;
		is >> t;
		a = ModLL<mod>(t);
		return (is);
	}
};
using mod2ll = ModLL<2>;

void exec(){

}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
