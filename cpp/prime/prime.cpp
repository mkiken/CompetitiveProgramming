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
//#include <limits>
#include <sstream>
//#include <functional>
using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define rrep(i, e, s) for(int i = (e);(s) <= i;i--)
#define Rrep(i, e) for(int i = e;0 <= i;i--)
#define mrep(i, e, t1, t2) for(map<t1, t2>::iterator i = e.begin(); i != e.end(); i++)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define vsort(v) sort(vrange(v))
#define vrsort(v) sort(vrrange(v))
#define arange(a) a, a + len(a)
#define asort(a) sort(arange(a))
#define arsort(a, t) sort(arange(a), greater<t>())
#define afill(a, v) fill(arange(a), v)
#define afill2(a, v, t) fill((t *)(a), (t *)((a) + len(a)), v)
#define fmax(a, b) ((a) < (b)? (b) : (a))
#define fmin(a, b) ((a) > (b)? (b) : (a))
#define fabs(a) ((a) < 0? -(a) : (a))
#define pb push_back
#define fst(e) (e).first
#define snd(e) (e).second
#define rg(e, s, t) (s <= e && e < t)
#define PQDecl(name, tp) priority_queue< tp, vector<tp>, greater<tp> > name
#define dq(q) q.top();q.pop();
#define sz(v) ((int)(v).size())
#define lg(s) ((int)(s).length())
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<int> VI;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};

void prtAI(int *a, int n){
    Rep(i, n) printf("%d%c", a[i], i==n-1?'\n':' ');
}
void prtVI(const VI &v){
    Rep(i, sz(v)) printf("%d%c", v[i], i==sz(v)-1?'\n':' ');
}
void prtP(P p){
  printf("%d, %d\n", p.first, p.second);
}
void prtVP(const vector<P> &vp){
    Rep(i, sz(vp)) prtP(vp[i]);
}

#define MAX_PRIMES 100002
#define PRIME_BUFFER 5
bool bPrimes[MAX_PRIMES+PRIME_BUFFER];
vector<int> primes;
int max_primes;

void initialize_prime_data(int max_prime){
  if (max_prime > MAX_PRIMES){
    printf("too large max_prime // %d\n", max_prime);
    exit(1);
  }
  afill(bPrimes, true);
  primes.clear();
  bPrimes[0] = bPrimes[1] = false;
  max_primes = max_prime;
}

void makePrimes(int max_prime){
  initialize_prime_data(max_prime);
  rep(i, 2, max_prime+PRIME_BUFFER){
    if(bPrimes[i]){
      primes.push_back(i);
      for(int j = 2*i; j < max_prime+PRIME_BUFFER; j += i) bPrimes[j] = false;
    }
  }
}

//偶数は無視する
void makePrimes2(int max_prime){
  initialize_prime_data(max_prime);
  primes.push_back(2);
  for(int i = 3; i < max_prime; i += 2){
    if(bPrimes[i]){
      primes.push_back(i);
      for(int j = 3*i; j < max_prime; j += 2*i) bPrimes[j] = false;
    }
  }
}

/**
 * @brief 素因数分解を行う
 * @param number 素因数分解する数
 * @return （素数、指数）を要素とするvector<P>
 */
vector<P> prime_factorize(ll number){
  if (primes.size() == 0){
    printf("not initialize primes\n");
    exit(1);
  }
  else if ((ll)max_primes * (ll)max_primes < number){
    printf("max_primes too small. // max_primes = %d, number = %lld\n", max_primes, number);
    exit(1);
  }
  vector<P> result;
  Rep(i, primes.size()){
    int div = 0;
    while(number % primes[i] == 0){
      div++;
      number /= primes[i];
    }
    if (div){
      result.push_back(P(primes[i], div));
    }
  }
  if (number > 1){
    result.push_back(P(number, 1));
  }
  return result;
}

void doIt(){
  // MillerRabinTest();
  makePrimes(100);
  prtVP(prime_factorize(100));
}

int main() {
  doIt();
  return 0;
}
