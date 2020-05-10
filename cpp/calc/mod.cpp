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
// const int mod = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (100000 + 2)

class ModCalculator {
private:
  int size;
  ll mod;
  VL facts;
  bool isMakeFacts = false;

public:
  ModCalculator(int _size, ll _mod) {
    size = _size;
    mod = _mod;
    facts = VL(_size + 2, 0);
  }

  void makeFacts(){
    facts[0] = 1;
    for (int i = 1; i <= size; i++){
      facts[i] = i * facts[i-1] % mod;
    }
    isMakeFacts = true;
  }

  void init() {
    makeFacts();
  }

  //n! mod m
  ll fact(int n) {
    assert(isMakeFacts && n <= size);
    return facts[n];
  }

  //nCk mod m
  ll comb(int n, int k){
    if(n < k) return 0;
    if(n - k < k) k = n - k;
    ll ans = fact(n);
    ans = ans * mod_inverse(fact(k)) % mod;
    ans = ans * mod_inverse(fact(n - k)) % mod;
    return ans;
  }

  ll rep_comb(int n, int k){
    return comb(n+k-1, k);
  }

  //区別のつかないn個のものを区別のつくk個に組み分け
  // http://www.minemura.org/juken/kumiwake.html
  ll group(int n, int k){
    return comb(n+k-1, k-1);
  }

  //n!/(a[0]!a[1]!..a[a.size()-1]!) mod m
  ll rep_perm(int n, vector<int> a){
    ll ret = fact(n), pdt = 1;
    for (int i = 0; i < a.size(); i++){
      pdt = (pdt * fact(a[i])) % mod;
    }
    return (ret * mod_inverse(pdt)) % mod;
  }

  //n**p % m
  ll pow(ll n, int p){
    ll ans = 1, ln = n % mod;
    if(p <= 0) return 1;
    while(p != 0){
      if((p & 1) == 1) ans = (ans*ln) % mod;
      ln = (ln * ln) % mod;
      p = p >> 1;
    }
    return ans;
  }

  // a x + b y = gcd(a, b)
  ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
  }

  // 1/a mod m
  ll mod_inverse(ll a){
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
  }
};

void exec(){
  ModCalculator mc = ModCalculator(100000, (int)1e9 + 7);

  mc.init();
  cout << mc.fact(100000) << endl;
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
