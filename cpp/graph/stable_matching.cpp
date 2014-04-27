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
typedef pair<ll, int> PL;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;
#define MAX_N 1000

const ll INIT = LLONG_MAX;
// const ll INIT = LLONG_MIN;


//orderM: i番目のMが好きなWの降順
//orderW: i番目のWが好きなMの降順
//Wから見たマッチングを返す
vector<int> stable_matching(const vector< vector<int> >& orderM,
                            const vector< vector<int> >& orderW) {
  const int N = orderM.size();
  vector< vector<int> > preferW(N, vector<int>(N+1, N));
  vector<int> matchW(N, N), proposedM(N);
  for (int w = 0; w < N; ++w)
    for (int i = 0; i < N; ++i)
      preferW[w][ orderW[w][i] ] = i;
  for (int m_ = 0; m_ < N; ++m_) {
    for (int m = m_; m < N; ) {
      int w = orderM[m][ proposedM[m]++ ];
      if (preferW[w][ m ] < preferW[w][ matchW[w] ])
        swap(m, matchW[w]);
    }
  }
  return matchW;
}


void doIt(){
  ll n, m, k, x, y, res;
  vector<P> a, b, bikers, bikes;
  vector< vector<int> > v1, v2;
  vector<int> ans;
  cin >> n >> m >> k;
  Rep(i, n){
    cin >> x >> y;
    a.pb(P(x, y));
  }
  Rep(i, m){
    cin >> x >> y;
    b.pb(P(x, y));
  }

  while(n < m){
      a.pb(P(-1, -1));
      n++;
  }
  while(m < n){
      b.pb(P(-1, -1));
      m++;
  }

  Rep(i, n){
    vector<PL> vv;
    Rep(j, m){
      if(a[i].first == -1 || b[j].first == -1){
        vv.pb(PL(INIT, j));
      }
      else{
        x = a[i].first - b[j].first;
        y = a[i].second - b[j].second;
        x = x*x;
        y = y*y;
        vv.pb(PL(x + y, j));
      }
    }
    vsort(vv);
    vector<int> v;
    Rep(j, m){
      v.pb(vv[j].second);
    }
    v1.pb(v);
  }
  Rep(i, n){
    vector<PL> vv;
    Rep(j, m){
      if(a[j].first == -1 || b[i].first == -1){
        vv.pb(PL(INIT, j));
      }
      else{
        x = b[i].first - a[j].first;
        y = b[i].second - a[j].second;
        x = x*x;
        y = y*y;
        vv.pb(PL(x + y, j));
      }
    }
    vsort(vv);
    vector<int> v;
    Rep(j, m){
      v.pb(vv[j].second);
    }
    v2.pb(v);
  }

  vector<ll> vans;
  ans = stable_matching(v1, v2);

  vans.clear();
  Rep(i, n){
    P e = b[ans[i]];
    if(a[i].first != -1 && e.first != -1){
      x = a[i].first - e.first;
      y = a[i].second - e.second;
      vans.pb(x*x + y*y);
    }
  }
  vsort(vans);
  res = vans[k-1];
  printf("res1 = %lld\n", res);

  ans = stable_matching(v2, v1);
  vans.clear();
  Rep(i, n){
    P e = a[ans[i]];
    if(b[i].first != -1 && e.first != -1){
      x = b[i].first - e.first;
      y = b[i].second - e.second;
      vans.pb(x*x + y*y);
    }
  }
  vsort(vans);
  res = fmin(vans[k-1], res);
  printf("res2 = %lld\n", vans[k-1]);

  printf("%lld\n", res);

}

int main() {
  doIt();
  return 0;
}
