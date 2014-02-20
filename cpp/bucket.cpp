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
#define MAX_N 10002
// #define B 100
#define B 100

ll bit[101][MAX_N];
int ary[10002];

void add(int idx, ll val, ll* ary){
  int p = idx+1;
  while(p < MAX_N){
    ary[p] += val;
    p += p & -p;
  }
}
ll sum(int idx, ll *ary){
  ll res = 0;
  int p = idx+1;
  while(0 < p){
    res += ary[p];
    p -= p & -p;
  }
  return res;
}
void change(int idx, ll val, ll* ary){
  ll s = sum(idx, ary) - sum(idx-1, ary);
  add(idx, val - s, ary);
}

// https://www.hackerrank.com/contests/feb14/challenges/library-query
void doIt(){
  int t, n, q, tmp, x, y, k, ans;
  scanf("%d", &t);
  while(t--){
    afill2(bit, 0, ll);
    scanf("%d", &n);
    Rep(i, n){
      scanf("%d", &tmp);
      add(tmp, 1, bit[i / B]);
      ary[i] = tmp;
    }
    scanf("%d", &q);
    Rep(i, q){
      scanf("%d", &tmp);
      if(tmp){
        scanf("%d%d", &x, &k);
        x--;
        add(ary[x], -1, bit[x / B]);
        add(k, 1, bit[x / B]);
        ary[x] = k;
      }
      else{
        scanf("%d%d%d", &x, &y, &k);
        x--;
        y--;
        int l = 1, r = 10002, m;
        while(l < r){
          m = (l + r) / 2;
          int tl = x, tr = y, tk_l = 0, tk_h = 0;

          while(tl < tr && tl % B != 0){
            tk_l += (ary[tl] < m);
            tk_h += (ary[tl] <= m);
            tl++;
          }
          while(tl < tr && tr % B != B-1){
            tk_l += (ary[tr] < m);
            tk_h += (ary[tr] <= m);

            tr--;
          }
          if(tr == tl){
            tk_l += (ary[tr] < m);
            tk_h += (ary[tr] <= m);
          }
          while(tl < tr){
            int b = tl / B;
            tk_l += sum(m-1, bit[b]);
            tk_h += sum(m, bit[b]);
            tl += B;
          }
          if(tk_l <= k && k <= tk_h){
            r = m;
            ans = m;
          }
          else if(tk_h < k){
            l = m + 1;
          }
          else{
            r = m;
          }
        }
        printf("%d\n", ans);
      }
    }
  }
}

int main() {
  doIt();
  return 0;
}
