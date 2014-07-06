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
#define MAX_N 100001

typedef struct _UNION_FIND{
  int par[MAX_N];
  int rank[MAX_N];
  void init(int n){
    rep(i, 0, n){
      par[i] = i;
      rank[i] = 0;
    }
  }
  int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) par[x] = y;
    else{
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y){
    return find(x) == find(y);
  }
} union_find;

// http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ACAC002&pid=B
void doIt(){
  int v, e, s[MAX_N], t[MAX_N], wt;
  P w[MAX_N];
  ll ans = 0;
  union_find uf;
  cin >> v >> e;
  uf.init(v+1);
  rep(i, 0, e){
    cin >> s[i] >> t[i] >> wt;
    w[i] = P(wt, i);
  }
  sort(w, w + e);
  rep(i, 0, e){
    int eid = w[i].second;
    if(!uf.same(s[eid], t[eid])){
      uf.unite(s[eid], t[eid]);
      ans += w[i].first;
    }
  }
  cout << ans << endl;
}

int main() {
  doIt();
  return 0;
}
