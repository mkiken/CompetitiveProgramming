#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream>
#include <functional>
#include <complex>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define Rep(i, e) for(int i = 0;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
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
#define afill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define fmax(a, b) (a < b? b : a)
#define fmin(a, b) (a > b? b : a)
#define fabs(a) (a < 0? -a : a)
#define pb push_back
#define rg(i, s, t) s <= i && i < t
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};
//priority_queue< int, vector<int>, greater<int> > q;
#define MAX_N 1000
#define log2 0.30102999566398119521373889472449L
// const double log2 = log10(2);

ll getFirstK(int n, int k){
  long double log = log2 * (n - 1);
  // double log = log2 * (n - 1);
  log -= (ll)log;
  // printf("log = %f\n", log);
  long double p = powl(10, log);
  // printf("pow = %f\n", p);
  // while(p < weight[k-1]){
  //   p *= 10;
  // }
  p *= powl(10, k-1);
  // printf("pow = %f\n", p);
  return (ll)p;
}

ll _powMod(int n, int p, int m){
  ll ans = 1, ln = n;
  if(p <= 0) return 1;
  while(p != 0){
	if((p & 1) == 1) ans = (ans*ln) % m;
	ln = (ln * ln) % m;
	p = p >> 1;
  }
  return ans;
}

ll getLastK(int n, int k){
  ll mod = pow(10, k);
  return _powMod(2, n-1, mod);
}

long long int lastkdigit(long long int K , long long int MOD)
{
    if(K==1) return 2;
    else if(K%2==0)
        {
            long long int temp = lastkdigit(K/2 , MOD);
            return (temp*temp)%MOD;
        }
     else
        {
            long long int temp = lastkdigit(K/2 , MOD);
            return (2*temp*temp)%MOD;
        }
}

void doIt(){
  int t, n, k;
  // printf("log2 = %.20Lf\n", log2);
  cin >> t;
  while(t--){
    cin >> n >> k;
    ll fst = getFirstK(n, k), lst = getLastK(n, k);
    // printf("fast = %lld\n", fst);
    // printf("lst = %lld\n", lst);
    // printf("lst2 = %lld\n", lastkdigit(n-1, weight[k]));
    printf("%lld\n", fst + lst);
  }
}

// https://www.hackerrank.com/blog/july-2020-editorial-journey-to-mars
int main() {
  doIt();
  return 0;
}
