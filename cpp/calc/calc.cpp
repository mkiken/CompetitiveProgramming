#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
//#include <stack>
//#include <limits>
#include <sstream>
//#include <functional>
#include <complex>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define vsort(v) sort(vrange(v))
#define vrsort(v) sort(vrrange(v))
#define arange(a) a, a + len(a)
#define asort(a) sort(arange(a))
#define arsort(a, t) sort(arange(a), greater<t>())
#define afill(a, v) fill(arange(a), v)
#define afill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define fmax(a, b) (a < b? b : a)
#define fmin(a, b) (a > b? b : a)
#define fabs(a) (a < 0? -a : a)
#define X real()
#define Y imag()
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef complex<double> p;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;

#define MAX_N 1000

double _combi[MAX_N+2][MAX_N+2]; //aCb = _combi[a][b]
void makeCombi(){
  rep(i, 0, MAX_N+1) _combi[i][0] = 1;
  rep(i, 1, MAX_N+1) _combi[0][i] = 0;
  rep(i, 1, MAX_N+1){
	rep(j, 1, i+1) _combi[i][j] = _combi[i-1][j-1] + _combi[i-1][j];
  }
}

//n**p
ll lpow(ll n, ll p){
  ll ans = 1, ln = n;
  if(p <= 0) return 1;
  while(p != 0){
	if((p & 1) == 1) ans = ans*ln;
	ln = ln * ln;
	p = p >> 1;
  }
  return ans;
}

//n**p
template <typename T> T fpow(T n, T p){
  T ans = 1, ln = n;
  if(p <= 0) return 1;
  while(p != 0){
    if((p & 1) == 1) ans = ans*ln;
    ln = ln * ln;
    p = p >> 1;
  }
  return ans;
}

//n**p % m
int powMod(ll n, int p){
  ll ans = 1, ln = n % MOD;
  if(p <= 0) return 1;
  while(p != 0){
	if((p & 1) == 1) ans = (ans*ln) % MOD;
	ln = (ln * ln) % MOD;
	p = p >> 1;
  }
  return (int)ans;
}

ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

// a x + b y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

// 1/a mod m
ll _mod_inverse(ll a, ll m){
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

// 1/a mod m
ll mod_inverse(ll a){
  ll x, y;
  extgcd(a, MOD, x, y);
  return (MOD + x % MOD) % MOD;
}

#define MAX_INV 1000000
ll inv[MAX_INV + 5];
void makeInv(int n){
  rep(i, 1, n + 1){
    inv[i] = mod_inverse(i);
  }
}

#define MAX_FACT 1000000
ll facts[MAX_FACT + 5];
void makeFacts(int n){
  facts[0] = 1;
  rep(i, 1, n + 1){
    facts[i] = i * facts[i-1] % MOD;
  }
}

int fcomb(int n, int k){
  ll l = 1, c = 1, ans;
  if(n < k) return 0;
  if(n - k < k) k = n - k;
  ans = facts[n];
  ans = ans * mod_inverse(facts[k]) % MOD;
  ans = ans * mod_inverse(facts[n - k]) % MOD;
  return (int)ans;
}

//InvがMAX_N内に収まるならこっちの方が速い
int _fcomb(int n, int k){
  ll l = 1, c = 1, ans;
  if(n < k) return 0;
  if(n - k < k) k = n - k;
  ans = facts[n];
  ans = ans * inv[facts[k]] % MOD;
  ans = ans * inv[facts[n - k]] % MOD;
  return (int)ans;
}

//n! mod m
int fact(int n){
  ll ret = 1;
  rep(i, 2, n+1) ret = (ret * i) % MOD;
  return (int)ret;
}

//nPk mod m
int perm(int n, int k, int m){
  ll ret = 1;
  rep(i, n-k+1, n+1) ret = (ret * i) % m;
  return (int)ret;
}

//nCk mod m
int comb(int n, int k){
  ll l = 1, c = 1;
  if(n < k) return 0;
  if(n - k < k) k = n - k;
  rep(i, 0, k){
	l = (l * (n - i)) % MOD;
	c = (c * (k - i)) % MOD;
  }
  return (int)((l * mod_inverse(c)) % MOD);
}

int rep_comb(int n, int k){
  return comb(n+k-1, k);
}

//n!/(a[0]!a[1]!..a[a.size()-1]!) mod m
int rep_perm(int n, vector<int> a){
  ll ret = fact(n), pdt = 1;
  rep(i, 0, a.size()) pdt = (pdt * fact(a[i])) % MOD;
  return (int)((ret * mod_inverse(pdt)) % MOD);
}

//区別のつかないn個のものを区別のつくk個に組み分け
// http://www.minemura.org/juken/kumiwake.html
int group(int n, int k){
  return comb(n+k-1, k-1);
}


//modを引数にとるバージョン

//n**p % m
int _powMod(int n, int p, int m){
  ll ans = 1, ln = n;
  if(p <= 0) return 1;
  while(p != 0){
	if((p & 1) == 1) ans = (ans*ln) % m;
	ln = (ln * ln) % m;
	p = p >> 1;
  }
  return (int)ans;
}

//n! mod m
int _fact(int n, int m){
  ll ret = 1;
  rep(i, 2, n+1) ret = (ret * i) % m;
  return (int)ret;
}

//nPk mod m
int _perm(int n, int k, int m){
  ll ret = 1;
  rep(i, n-k+1, n+1) ret = (ret * i) % m;
  return (int)ret;
}

//nCk mod m
int _comb(int n, int k, int m){
  ll l = 1, c = 1;
  if(n < k) return 0;
  if(n - k < k) k = n - k;
  rep(i, 0, k){
	l = (l * (n - i)) % m;
	c = (c * (k - i)) % m;
  }
  return (int)((l * _mod_inverse(c, m)) % m);
}

//n!/(a[0]!a[1]!..a[a.size()-1]!) mod m
int _rep_perm(int n, vector<int> a, int m){
  ll ret = _fact(n, m), pdt = 1;
  rep(i, 0, a.size()) pdt = (pdt * _fact(a[i], m)) % m;
  return (int)((ret * _mod_inverse(pdt, m)) % m);
}

//calculate (a*b)%m
//http://discuss.codechef.com/questions/9723/witmath-editorial
ull _bigMul(ull a, ull b, int m){
	int base = (int)1e9;
	ull a_low = a % base, a_high = a / base, b_low = b % base, b_high = b / base, result;
	result = (a_high * b_high) % m;
	rep(i, 0, 9) result = (result * 10) % m;
	result = (result + a_low*b_high + b_low*a_high) % m;
	rep(i, 0, 9) result = (result * 10) % m;
	result = (result + a_low*b_low) % m;
	return result;
}

// http://stackoverflow.com/questions/1549941/perfect-square-and-perfect-cube
bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}
bool is_perfect_cube(int n) {
    int root(round(cbrt(n)));
    return n == root * root * root;
}

void doIt(){
    // cout << _comb(10, 10, MOD) << endl;
    cout << gcd(10, 15) << endl;
}

int main() {
  doIt();
  return 0;
}
