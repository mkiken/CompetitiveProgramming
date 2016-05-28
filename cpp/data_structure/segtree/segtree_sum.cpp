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

//Segment Tree for sum value.
ll all[MAX_SIZE], part[MAX_SIZE];
//区間[a, b)に値xを加算する.
void _addSum(int a, int b, int x, int k, int l, int r){
  if (a <= l && r <= b) all[k] += x;
  else if (l < b && a < r){
	part[k] += (min(b, r) - max(a, l)) * x;
	_addSum(a, b, x, k * 2 + 1, l, (l + r) / 2);
	_addSum(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }
}
ll _getSum(int a, int b, int k, int l, int r){
  if (b <= l || r <= a) return 0;
  else if (a <= l && r <= b) return (all[k] * (r - l) + part[k]);
  else {
	ll res;
	res = (min(b, r) - max(a, l)) * all[k];
	res += _getSum(a, b, k * 2 + 1, l, (l + r) / 2);
	res += _getSum(a, b, k * 2 + 2, (l + r) / 2, r);
	return res;
  }
}

/**
 * 区間[a, b]に値xを加算する.
 * sizeは木の要素数
 */
void addSum(int a, int b, int x, int size){
  _addSum(a, b+1, x, 0, 0, size+1);
}

/**
 * 区間[a, b]の合計値を取得.
 * sizeは木の要素数
 */
ll getSum(int a, int b, int size){
  _getSum(a, b+1, 0, 0, size+1);
}

void doIt(){
}

int main() {
  doIt();
  return 0;
}
