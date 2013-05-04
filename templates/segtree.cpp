#include <iostream>
#include <cstdio>
//#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
//#include <map>
//#include <set>
//#include <queue>
//#include <limits>
//#include <sstream>
//#include <functional>
using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v, t) sort(v.begin(), v.end(), greater<t>())
#define asort(a) sort(a, a + len(a))
#define rasort(a, t) sort(a, a + len(a), greater<t>())
#define dmax(a, b) (a < b? b : a)
#define dmin(a, b) (a > b? b : a)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
typedef struct _Node {
  _Node(int arg1 = 0, int arg2 = 0 , int arg3 = 0) {
	i = arg1;
	j = arg2;
	k = arg3;
  }
  int i,j,k;
  bool operator <(const struct _Node &e) const{
    return i == e.i? j < e.j : i < e.i;
  }
  bool operator >(const struct _Node &e) const{
    return i == e.i? j > e.j : i > e.i;
  }
}node;

#define MAX_N 100000
#define MAX_SIZE MAX_N * 4

//Starry Sky Tree
//http://kagamiz.hatenablog.com/entry/2012/12/18/220849

//Segment Tree for minimum value.
ll segMin[MAX_SIZE], segAddMin[MAX_SIZE];

//区間[a, b)に値xを加算する.
void addMin(int a, int b, int x, int k, int l, int r)
{
  if (r <= a || b <= l) return;

  if (a <= l && r <= b){
	segAddMin[k] += x;
	while (k){
	  k = (k - 1) / 2;
	  segMin[k] = min(segMin[k * 2 + 1] + segAddMin[k * 2 + 1], segMin[k * 2 + 2] + segAddMin[k * 2 + 2]);
	}
	return;
  }

  addMin(a, b, x, k * 2 + 1, l, (l + r) / 2);
  addMin(a, b, x, k * 2 + 2, (l + r) / 2, r);
}

ll getMin(int a, int b, int k, int l, int r)
{
  if (r <= a || b <= l) return INF;
  if (a <= l && r <= b) return (segMin[k] + segAddMin[k]);
  ll left = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
  ll right = getMin(a, b, k * 2 + 2, (l + r) / 2, r);
  return (min(left, right) + segAddMin[k]);
}


//Segment Tree for maximum value.

ll segMax[MAX_SIZE], segAddMax[MAX_SIZE];

//区間[a, b)に値xを加算する.
void addMax(int a, int b, int x, int k, int l, int r)
{
  if (r <= a || b <= l) return;
  if (a <= l && r <= b){
	segAddMax[k] += x;
	while (k){
	  k = (k - 1) / 2;
	  segMax[k] = max(segMax[k * 2 + 1] + segAddMax[k * 2 + 1], segMax[k * 2 + 2] + segAddMax[k * 2 + 2]);
	}
	return;
  }

  addMax(a, b, x, k * 2 + 1, l, (l + r) / 2);
  addMax(a, b, x, k * 2 + 2, (l + r) / 2, r);
}

ll getMax(int a, int b, int k, int l, int r)
{
  if (r <= a || b <= l) return -1;
  if (a <= l && r <= b) return (segMax[k] + segAddMax[k]);
  ll left = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
  ll right = getMax(a, b, k * 2 + 2, (l + r) / 2, r);
  return (max(left, right) + segAddMax[k]);
}


//Segment Tree for sum value.

ll all[MAX_SIZE], part[MAX_SIZE];

//区間[a, b)に値xを加算する.
void addSum(int a, int b, int x, int k, int l, int r)
{
  if (a <= l && r <= b) all[k] += x;
  else if (l < b && a < r){
	part[k] += (min(b, r) - max(a, l)) * x;
	addSum(a, b, x, k * 2 + 1, l, (l + r) / 2);
	addSum(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }
}

ll getSum(int a, int b, int k, int l, int r)
{
  if (b <= l || r <= a) return 0;
  else if (a <= l && r <= b) return (all[k] * (r - l) + part[k]);
  else {
	ll res;
	res = (min(b, r) - max(a, l)) * all[k];
	res += getSum(a, b, k * 2 + 1, l, (l + r) / 2);
	res += getSum(a, b, k * 2 + 2, (l + r) / 2, r);
	return res;
  }
}



void doIt(){
  int n, b, q, l, r;
  mfill(segMin, 0);
  mfill(segAddMin, 0);
  mfill(segMax, 0);
  mfill(segAddMax, 0);
  cin >> n;
  rep(i, 0, n){
	cin >> b;
	addMin(i, i+1, b, 0, 0, n);
	addMax(i, i+1, b, 0, 0, n);
  }
  cin >> q;
  while(q--){
	ll mmin, mmax;
	double res;
	cin >> l >> r;
	mmin = getMin(l, r+1, 0, 0, n);
	mmax = dmax(getMax(0, l, 0, 0, n), 0);
	mmax = max(getMax(r+1, n, 0, 0, n), mmax);
	if(l == r) res = dmax(mmin, mmin + mmax);
	else{
	  res = mmin + dmax((getMax(l, r+1, 0, 0, n) - mmin), 0) / 2.0;
	  res = dmax(res, mmin + mmax);
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
