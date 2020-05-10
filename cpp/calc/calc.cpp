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

class Calc {
public:
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
  ll mod_inverse(ll a, ll m){
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }

  //n**p % m
  ll powMod(int n, int p, int m){
    ll ans = 1, ln = n;
    if(p <= 0) return 1;
    while(p != 0){
      if((p & 1) == 1) ans = (ans*ln) % m;
      ln = (ln * ln) % m;
      p = p >> 1;
    }
    return ans;
  }

  //n! mod m
  ll fact(int n, int m){
    ll ret = 1;
    for (int i = 2; i <= n; i++){
      ret = (ret * i) % m;
    }

    return ret;
  }

  //nPk mod m
  ll perm(int n, int k, int m){
    ll ret = 1;
    for (int i = n - k + 1; i <= n; i++){
      ret = (ret * i) % m;
    }
    return ret;
  }

  //nCk mod m
  ll comb(int n, int k, int m){
    ll l = 1, c = 1;
    if(n < k) return 0;
    if(n - k < k) k = n - k;
    for (int i = 0; i < k; i++){
      l = (l * (n - i)) % m;
      c = (c * (k - i)) % m;
    }
    return (l * mod_inverse(c, m)) % m;
  }

  //n!/(a[0]!a[1]!..a[a.size()-1]!) mod m
  ll rep_perm(int n, vector<int> a, int m){
    ll ret = fact(n, m), pdt = 1;
    for (int i = 0; i < a.size(); i++){
      pdt = (pdt * fact(a[i], m)) % m;
    }
    return (ret * mod_inverse(pdt, m)) % m;
  }

  //calculate (a*b)%m
  //http://discuss.codechef.com/questions/9723/witmath-editorial
  ull bigMul(ull a, ull b, int m){
    int base = (int)1e9;
    ull a_low = a % base, a_high = a / base, b_low = b % base, b_high = b / base, result;
    result = (a_high * b_high) % m;
    for (int i = 0; i < 9; i++){
      result = (result * 10) % m;
    }
    result = (result + a_low*b_high + b_low*a_high) % m;
    for (int i = 0; i < 9; i++){
      result = (result * 10) % m;
    }
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

};

void doIt(){
  Calc c = Calc();
  cout << c.gcd(10, 15) << endl;
}

int main() {
  doIt();
  return 0;
}
