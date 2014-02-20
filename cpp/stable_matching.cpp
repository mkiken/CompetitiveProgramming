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
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;
#define MAX_N 1000


template <typename T> vector<int> stable_matching(const vector< vector<ll> >& orderM,
                            const vector< vector<ll> >& orderW) {
  const int N = orderM.size();
  vector< vector<ll> > preferW(N, vector<ll>(N+1, N));
  vector<int> matchW(N, N), proposedM(N);
  for (int w = 0; w < N; ++w)
    for (int i = 0; i < N; ++i)
      preferW[w][ orderW[w][i] ] = i;
  for (int m_ = 0; m_ < N; ++m_) {
    for (int m = m_; m < N; ) {
      ll w = orderM[m][ proposedM[m]++ ];
      if (preferW[w][ m ] < preferW[w][ matchW[w] ]) swap(m, matchW[w]);
    }
  }
  return matchW;
}

void doIt(){
  ll n, m, k, x, y;
  vector<P> bikers, bikes, a, b;
  vector< vector<ll> > v;
  vector<ll> ans, res;
  cin >> n >> m >> k;
  Rep(i, n){
    cin >> x >> y;
    bikers.pb(P(x, y));
  }
  Rep(i, m){
    cin >> x >> y;
    bikes.pb(P(x, y));
  }
  if(n <= m){
    a = bikers;
    b = bikes;
  }
  else{
    a = bikes;
    b = bikers;
    swap(n, m);
  }
  Rep(i, n){
    vector<ll> vv;
    Rep(j, m){
      x = a[i].first - b[j].first;
      y = a[i].second - b[j].second;
      x = x*x;
      y = y*y;
      vv.pb(x + y);
    }
    v.pb(vv);
  }
  // ans = hungurian(v);
  // Rep(i, ans.size()){
  //   prllf("%lld ", ans[i]);
  // }
  // printf("\n");
  Rep(i, n){
    res.pb(v[i][ans[i]]);
  }
  vsort(res);
  cout << res[k-1] << endl;

}

int main() {
  doIt();
  return 0;
}
