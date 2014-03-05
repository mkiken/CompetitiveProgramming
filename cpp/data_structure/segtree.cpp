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
//区間[a, b)に値xを加算する.sizeは木の要素数
void addMin(int a, int b, int x, int size){
  _addMin(a, b, x, 0, 0, size);
}
ll getMin(int a, int b, int size){
  return _getMin(a, b, 0, 0, size);
}

//Segment Tree for maximum value.
ll segMax[MAX_SIZE], segAddMax[MAX_SIZE];
void _addMax(int a, int b, int x, int k, int l, int r){
  if (r <= a || b <= l) return;
  if (a <= l && r <= b){
	segAddMax[k] += x;
	while (k){
	  k = (k - 1) / 2;
	  segMax[k] = fmax(segMax[k * 2 + 1] + segAddMax[k * 2 + 1], segMax[k * 2 + 2] + segAddMax[k * 2 + 2]);
	}
	return;
  }
  _addMax(a, b, x, k * 2 + 1, l, (l + r) / 2);
  _addMax(a, b, x, k * 2 + 2, (l + r) / 2, r);
}
ll _getMax(int a, int b, int k, int l, int r){
  if (r <= a || b <= l) return -1;
  if (a <= l && r <= b) return (segMax[k] + segAddMax[k]);
  ll left = _getMax(a, b, k * 2 + 1, l, (l + r) / 2);
  ll right = _getMax(a, b, k * 2 + 2, (l + r) / 2, r);
  return fmax(left, right) + segAddMax[k];
}
//区間[a, b)に値xを加算する.
void addMax(int a, int b, int x, int size){
  _addMax(a, b, x, 0, 0, size);
}
ll getMax(int a, int b, int size){
  return _getMax(a, b, 0, 0, size);
}


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
void addSum(int a, int b, int x, int size){
  _addSum(a, b, x, 0, 0, size);
}
ll getSum(int a, int b, int size){
  _getSum(a, b, 0, 0, size);
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
