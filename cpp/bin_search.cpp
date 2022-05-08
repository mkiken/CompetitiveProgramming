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
#define rg(e, s, t) s <= e && e < t
#define PQDecl(name, tp) priority_queue< tp, vector<tp>, greater<tp> > name
#define dq(q) q.top();q.pop();
#define sz(v) ((int)(v).size())
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};
#define MAX_N 100005
#define BIN_SEARCH_MAX 1000
#define BIN_SEARCH_MIN 0

bool check(ll u){
  return true;
}

// checkを満たす最大の値を二分探索で求める
ll max_bin_search(){
  ll u = BIN_SEARCH_MAX; //BIN_SEARCH_MAXは探索空間の最大値
  ll l = BIN_SEARCH_MIN; //BIN_SEARCH_MINは探索空間の最小値
  if(check(l) == false){return BIN_SEARCH_MIN - 1;} //最小値でfalseだったら全部false

  ll m = (l + u) / 2 + (l + u) % 2; //切り捨てではなく切り上げ
  while(l < u){
    m = (l + u) / 2 + (l + u) % 2;
    if(check(m) == false) u = m - 1; //mは探索空間外
    else l = m; //mはまだ探索空間に残しておく
  }
  return (u + l) / 2;
}

// checkを満たす最小の値を二分探索で求める
ll min_bin_search(){
  ll u = BIN_SEARCH_MAX; //BIN_SEARCH_MAXは探索空間の最大値
  ll l = BIN_SEARCH_MIN; //BIN_SEARCH_MINは探索空間の最小値
  if(check(u) == false){return BIN_SEARCH_MAX + 1;} //最大値でfalseだったら全部false
  ll m = (l + u) / 2;
  while(l < u){
    m = (l + u) / 2;
    if(check(m)) u = m; //mはまだ探索空間に残しておく
    else l = m + 1; //mは探索空間外
  }
  return (u + l) / 2;
}

void doIt(){
  int t = 1;
  // scanf("%d", &t);
  while(t--){
    min_bin_search();
  }
}

int main() {
  doIt();
  return 0;
}
