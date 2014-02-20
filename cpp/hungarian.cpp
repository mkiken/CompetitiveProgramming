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

// http://nya3.jp/libicpc/?%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA%2F%E3%82%B0%E3%83%A9%E3%83%95%2F%E3%83%9E%E3%83%83%E3%83%81%E3%83%B3%E3%82%B0%2F%E3%83%8F%E3%83%B3%E3%82%AC%E3%83%AA%E3%82%A2%E3%83%B3%E6%B3%95
//Hungarian method -> O(n^3)
//requirement: n <= m
//コストの小さい最適解を出す
#define residue(i,j) (adj[i][j] + ofsleft[i] + ofsright[j])
template <typename T> vector<T> hungurian(vector< vector<T> > adj) {
    int n = adj.size();
    int m = adj[0].size();
    vector<T> toright(n, -1), toleft(m, -1);
    vector<T> ofsleft(n, 0), ofsright(m, 0);
    Rep(r, n) {
        vector<bool> left(n, false), right(m, false);
        vector<T> trace(m, -1), ptr(m, r);
        left[r] = true;
        for(;;) {
            T d = numeric_limits<T>::max();
            Rep(j, m)
              // if (!right[j]) d <?= residue(ptr[j], j);
              if (!right[j]) d = fmin(residue(ptr[j], j), d);
            Rep(i, n)
              if (left[i]) ofsleft[i] -= d;
            Rep(j, m)
              if (right[j]) ofsright[j] += d;
            T b = -1;
            Rep(j, m)
              if (!right[j] && residue(ptr[j], j) == 0) b = j;
            trace[b] = ptr[b];
            T c = toleft[b];
            if (c < 0) {
                while(b >= 0) {
                    T a = trace[b];
                    T z = toright[a];
                    toleft[b] = a;
                    toright[a] = b;
                    b = z;
                }
                break;
            }
            right[b] = left[c] = true;
            Rep(j, m)
              if (residue(c, j) < residue(ptr[j], j)) ptr[j] = c;
        }
    }
    return toright;
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
  ans = hungurian(v);
  // Rep(i, ans.size()){
  //   printf("%lld ", ans[i]);
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
