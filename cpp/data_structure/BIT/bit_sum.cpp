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
/*
  Binary Indexed Tree

  void add(int idx, ll val, ll* ary)
  BIT aryのidxにvalを追加する．
  idxは0-indexed.idx = -1で0を返す(ary[0]にアクセス)．

  ll sum(int idx, ll *ary)
  idxまでの総和を求める．
  idx = -1で0を返す（ary[0]までの総和）．

  void change(int idx, ll val, ll* ary)
  idx番目をvalに変更する．

 */


#define MAX_N 100000 + 2
ll bit[MAX_N + 1];
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

ll bit1[MAX_N];
void badd(int l, int r, ll val){
  add(l, -val * (l - 1), bit);
  add(l, val, bit1);
  add(r + 1, r * val, bit);
  add(r + 1, -val, bit1);
}
ll ssum(int idx){
  return sum(idx, bit1) * idx + sum(idx, bit);
}

//転倒数を求める（蟻本）
// void doIt(){
// 	int t, n, a[MAX_N];
// 	ll ans = 0;
// 	cin >> t;
// 	while(t--){
// 		cin >> n;
// 		Rep(i, n) cin >> a[i];
// 		ans = 0;
// 		fill(bit0, bit0 + n + 1, 0);
// 		Rep(i, n){
// 			ans += i - sum(a[i], bit0);
// 			add(a[i], 1, bit0);
// 		}
// 		cout << ans << endl;
// 	}
// }

//http://www.codechef.com/ODCD2013/problems/LETHOR
// void doIt(){
// 	int t, n, a[MAX_N], b[MAX_N];
// 	ll ans = 0;
// 	vector<P> v;
// 	cin >> t;
// 	while(t--){
// 		cin >> n;
// 		v.clear();
// 		Rep(i, n) cin >> b[i], v.pb(P(b[i], i));
// 		vsort(v);
// 		Rep(i, n){
// 			a[v[i].second] = i+1;
// 		}
// 		ans = 0;
// 		fill(bit0, bit0 + n + 1, 0);
// 		Rep(i, n){
// 			ans += i - sum(a[i], bit0);
// 			add(a[i], 1, bit0);
// 		}
// 		cout << ans << endl;
// 	}
// }

void doIt(){
  add(0, 2, bit);
  add(1, 5, bit);
  add(2, 15, bit);
  cout << sum(0, bit) << endl;
  cout << sum(1, bit) << endl;
  cout << sum(2, bit) << endl;
  change(0, 27, bit);
  cout << sum(0, bit) << endl;
  cout << sum(1, bit) << endl;
  cout << sum(2, bit) << endl;
}

void doIt2(){
  badd(0, 5, 10);
  badd(0, 1, 100);
  cout << ssum(0) << endl;
  cout << ssum(4) << endl;
  cout << ssum(5) << endl;
  cout << ssum(0) << endl;
}

int main() {
  doIt();
  return 0;
}
