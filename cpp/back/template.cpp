#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <cassert>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define rrep(i, e, s) for(int i = (e);(s) <= i;i--)
#define Rrep(i, e) for(int i = e;0 <= i;i--)
#define maprep(i, e, t1, t2) for(map<t1, t2>::iterator i = e.begin(); i != e.end(); i++)
#define setrep(i, e, t) for(set<t>::iterator i = e.begin(); i != e.end(); i++)
#define vrange(v) v.begin(), v.end()
#define vrrange(v) v.rbegin(), v.rend()
#define vsort(v) sort(vrange(v))
#define vrsort(v) sort(vrrange(v))
#define arange(a) a, a + len(a)
#define asort(a) sort(arange(a))
#define arsort(a, t) sort(arange(a), greater<t>())
#define afill(a, v) fill(arange(a), v)
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
typedef struct _Datum {
  int fst,snd,trd;
  _Datum(int arg1 = 0, int arg2 = 0 , int arg3 = 0) {
	fst = arg1; snd = arg2; trd = arg3;
  }
  bool operator <(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd < e.trd : snd < e.snd) : fst < e.fst;
  }
  bool operator >(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd > e.trd : snd > e.snd) : fst > e.fst;
  }
}datum;

void draw_line(){
  printf("\n-----------------------------\n\n");
}
template<typename T>
void prtA(const T &a, int n = 0){
  draw_line();
  if (!n) n = len(a);
    Rep(i, n) printf("%d%c", a[i], i==n-1?'\n':' ');
  draw_line();
}
template<typename T>
void prtA2d(const T &a, int x = 0, int y = 0){
  draw_line();
  if (!x) x = len(a);
  if (!y) y = len(*a);
    Rep(i, x) Rep(j, y) printf("%d%c", a[i][j], j % y == y-1?'\n':' ');
  draw_line();
}
template<typename T>
void prtA3d(const T &a, int x = 0, int y = 0, int z = 0){
  draw_line();
  if (!x) x = len(a);
  if (!y) y = len(*a);
  if (!z) z = len(**a);
    Rep(i, x) Rep(j, y) Rep(k, z){
      printf("%d%s", a[i][j][k], k % z == z-1? (j % y == y-1?"\n\n":"\n"):" ");
    }
  draw_line();
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

// C++ 11+ only. use 'g++ -std=c++11' when compile.
template<typename T, typename... Rest>
int fmax(const T& a, const Rest&... rest)
{
  T b = fmax(rest...);
  return ((a) < (b)? (b) : (a));
}
template<typename T, typename... Rest>
int fmin(const T& a, const Rest&... rest)
{
  T b = fmin(rest...);
  return ((a) > (b)? (b) : (a));
}
template<typename T, typename T2>
void afill2(T &a, const T2 v)
{
  fill((T2 *)(a), (T2 *)((a) + len(a)), v);
}


#define MAX_N 100005

void solve(){
}

void doIt(){
  int t = 1;
  // scanf("%d", &t);
  while(t--){
    solve();
  }
}

int main() {
  doIt();
  return 0;
}
