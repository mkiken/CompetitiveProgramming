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


void prtAI(int *a, int n, bool display = true){
    if(display) printf("---printAI---\n");
    Rep(i, n) printf("%d%c", a[i], i==n-1?'\n':' ');
    if(display) printf("-----------------\n");
}
void prtVI(const VI &v, bool display = true){
    if(display) printf("-----printVI-----\n");
    Rep(i, sz(v)) printf("%d%c", v[i], i==sz(v)-1?'\n':' ');
    if(display) printf("-----------------\n");
}

#define MAX_N 300005
#define MAX_LOGN 20

int gcd(int a, int b){
  return b == 0? a : gcd(b, a % b);
}


/*Sparse Table
  http://www.topcoder.com/tc?d1=tutorials&d2=lowestCommonAncestor&module=Static
  the overall complexity of the algorithm is <O(N logN), O(1)> (<construction, query>).
 */

int n, a[MAX_N], dp_min[MAX_N][MAX_LOGN + 1], dp_gcd[MAX_N][MAX_LOGN + 1];

// http://codeforces.com/contest/359/problem/D
void solve(){

  afill2(dp_gcd, -1, int);
  afill2(dp_min, INF, int);
  scanf("%d", &n);

  Rep(i, n) {
    scanf("%d", &a[i]);
    dp_min[i][0] = dp_gcd[i][0] = a[i];
  }

  rep(j, 1, MAX_LOGN + 1){
    Rep(i, n){
      int tv = i + (1 << (j-1));
      if(tv >= n) continue;
      if(dp_min[tv][j-1] == INF) continue;
      dp_min[i][j] = min(dp_min[i][j-1], dp_min[tv][j-1]);
      dp_gcd[i][j] = gcd(dp_gcd[i][j-1], dp_gcd[tv][j-1]);
    }
  }

  int h = n, l = 0, m, l2;
  bool bOK;
  while(l < h){
    m = (l + h) / 2 + (l + h) % 2;
    l2 = (int)log2(m);
    bOK = false;

    Rep(i, n - m){
      int tmin = min(dp_min[i][l2], dp_min[i + m - (1 << l2)+1][l2]);
      int tgcd = gcd(dp_gcd[i][l2], dp_gcd[i + m - (1 << l2)+1][l2]);

      if(tmin == tgcd){
        bOK = true;
      }
    }

    if(bOK){
      l = m;
    } else {
      h = m - 1;
    }
  }

  m = (l + h) / 2 + (l + h) % 2;
  if(m == 0){
    printf("%d 0\n", n);
    Rep(i, n-1){
      printf("%d ", i+1);
    }
    printf("%d\n", n);
    return;
  }

  l2 = (int)log2(m);
  vector<int> v;

  Rep(i, n - m){
    int tmin = min(dp_min[i][l2], dp_min[i + m - (1 << l2)+1][l2]);
    int tgcd = gcd(dp_gcd[i][l2], dp_gcd[i + m - (1 << l2)+1][l2]);

    if(tmin == tgcd){
      v.pb(i+1);
    }
  }

  printf("%d %d\n", sz(v), m);
  Rep(i, sz(v)-1){
    printf("%d ", v[i]);
  }
  printf("%d\n", v[sz(v)-1]);
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
