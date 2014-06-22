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

void prtAI(int *a, int n){
    Rep(i, n) printf("%d%c", a[i], i==n-1?'\n':' ');
}
void prtVI(const VI &v){
    Rep(i, sz(v)) printf("%d%c", v[i], i==sz(v)-1?'\n':' ');
}


#define MAX_N 105
int dp[MAX_N][MAX_N];
int h, w, field[102][102];

// http://arc025.contest.atcoder.jp/tasks/arc025_2
void solve(){
  scanf("%d%d", &h, &w);
  afill2(dp, 0, int);

  Rep(i, h){
    Rep(j, w){
      scanf("%d", &field[i][j]);
      if((i+j) % 2){
        field[i][j] *= -1;
      }
    }
  }

  Rep(i, h){
    Rep(j, w){
      dp[i+1][j+1] += dp[i][j+1];
      dp[i+1][j+1] += dp[i+1][j];
      dp[i+1][j+1] -= dp[i][j];
      dp[i+1][j+1] += field[i][j];
    }
  }

  int ans = 0;
  Rep(i, h){
    Rep(j, w){
      rep(k, 1, h-i+1){
        rep(l, 1, w-j+1){
          int i2 = i + k, j2 = j + l;
          int val = dp[i2][j2] - dp[i][j2] - dp[i2][j] + dp[i][j];
          if(val == 0){
            ans = max(ans, k*l);
          }
        }
      }
    }
  }
  printf("%d\n", ans);

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
