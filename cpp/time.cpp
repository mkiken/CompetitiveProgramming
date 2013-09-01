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
//#include <stack>
//#include <limits>
#include <sstream>
//#include <functional>
#include <complex>
#include <ctime>

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
#define X real()
#define Y imag()
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef complex<double> p;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;

//struct tm : http://www.tamasoft.co.jp/lc/hlp/F047.html

//閏年ならtrue
bool leap(int y){
  return y % 400 == 0? true : (y % 100 == 0? false : (y % 4 == 0? true : false));
}

void settime(struct tm *t, int y, int m, int d){
  t->tm_sec = 0;
  t->tm_min = 0;
  t->tm_hour = 0;
  t->tm_mday = d;
  t->tm_mon = m-1;
  t->tm_year = y-1900;
  // if(leap(y)) t->tm_yday = 365;
  // else t->tm_yday = 364;
  t->tm_isdst = -1;
}

int diffdays(struct tm *t1, struct tm *t2){
  double t = difftime(mktime(t1), mktime(t2));
  return fabs(t) / (60*60*24);
}

//AOJ0125
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0125
void doIt(){
  int y1,m1,d1,y2,m2,d2;
  struct tm t1, t2;
  int ans;
  while(1){
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	if(y1 < 0) break;
	settime(&t1, y1, m1, d1);
	settime(&t2, y2, m2, d2);
	ans = diffdays(&t1, &t2);
	cout << ans << endl;
  }
}

void test(){
  struct tm t1, t2;
  settime(&t1, 2000, 2, 28);
  settime(&t2, 2000, 3, 1);
  cout << diffdays(&t1, &t2) << endl;
}

int main() {
  doIt();
  //test();
  return 0;
}
