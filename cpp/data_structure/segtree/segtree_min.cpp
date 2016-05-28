#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
//#include <limits>
#include <sstream>
//#include <functional>
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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;

#define MAX_N 100002
#define MAX_SIZE MAX_N * 4

//Starry Sky Tree
//http://kagamiz.hatenablog.com/entry/2012/12/18/220849

//Segment Tree for minimum value.
ll segMin[MAX_SIZE], segAddMin[MAX_SIZE];
void _addMin(int a, int b, int x, int k, int l, int r){
  if (r <= a || b <= l) return;
  if (a <= l && r <= b){
	segAddMin[k] += x;
	while (k){
	  k = (k - 1) / 2;
	  segMin[k] = fmin(segMin[k * 2 + 1] + segAddMin[k * 2 + 1], segMin[k * 2 + 2] + segAddMin[k * 2 + 2]);
	}
	return;
  }
  _addMin(a, b, x, k * 2 + 1, l, (l + r) / 2);
  _addMin(a, b, x, k * 2 + 2, (l + r) / 2, r);
}
ll _getMin(int a, int b, int k, int l, int r){
  if (r <= a || b <= l) return INF;
  if (a <= l && r <= b) return (segMin[k] + segAddMin[k]);
  ll left = _getMin(a, b, k * 2 + 1, l, (l + r) / 2);
  ll right = _getMin(a, b, k * 2 + 2, (l + r) / 2, r);
  return fmin(left, right) + segAddMin[k];
}

/**
 * 区間[a, b]に値xを加算する.
 * sizeは木の要素数
 */
void addMin(int a, int b, int x, int size){
  _addMin(a, b+1, x, 0, 0, size+1);
}

/**
 * 区間[a, b]の最小値を取得.
 * sizeは木の要素数
 */
ll getMin(int a, int b, int size){
  return _getMin(a, b+1, 0, 0, size+1);
}

void doIt(){
  int n, b, q, l, r;
  afill(segMin, 0);
  afill(segAddMin, 0);
  afill(segMax, 0);
  afill(segAddMax, 0);
  cin >> n;
  rep(i, 0, n){
	  cin >> b;
	  addMin(i, i+1, b, n);
	  addMax(i, i+1, b, n);
  }
  cin >> q;
  while(q--){
	  ll mmin, mmax;
	  double res;
	  cin >> l >> r;
	  mmin = getMin(l, r+1, n);
	  mmax = fmax(getMax(0, l, n), 0);
	  mmax = max(getMax(r+1, n, n), mmax);
	  if(l == r) res = fmax(mmin, mmin + mmax);
	  else{
	    res = mmin + fmax((getMax(l, r+1, n) - mmin), 0) / 2.0;
	    res = fmax(res, mmin + mmax);
	  }
	  printf("%.1f\n", res);
  }
}

//code from CodeChef Matchsticks
//http://ww2.codechef.com/MAY13/problems/MSTICK
int main() {
  doIt();
  return 0;
}
