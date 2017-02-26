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
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;


// http://d.hatena.ne.jp/otaks/20100929
// http://www.cplusplus.com/reference/complex/
typedef complex<double> p;
//XY座標
#define X real()
#define Y imag()


//二次元座標(from 蟻本)
typedef struct _PT{
  double x, y;
  _PT() {}
  _PT(double x, double y) : x(x), y(y){
  }
  _PT operator + (_PT p){
    return _PT(x + p.x, y + p.y);
  }
  _PT operator - (_PT p){
    return _PT(x - p.x, y - p.y);
  }
  _PT operator * (double d){
    return _PT(d*x, d*y);
  }
  double dot(_PT p){ //pとの内積
    return x * p.x + y * p.y;
  }
  double det(_PT p){ //pとの外積
    return x * p.y - p.x * y;
  }
  double dist(_PT p){ //pとの距離の2乗
    return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
  }
  double abs(){
    return sqrt(norm());
  }
  double norm(){
    return x*x + y*y;
  }
  bool operator <(const struct _PT &e) const{
    return x == e.x? (y < e.y) : x < e.x;
  }
  bool operator >(const struct _PT &e) const{
    return x == e.x? (y > e.y) : x > e.x;
  }
} pt;
// 線分p1-p2上に点qがあるか判定
bool on_seg(pt p1, pt p2, pt q){
  return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
// 直線p1-p2とq1-q2の交点
pt intersection(pt p1, pt p2, pt q1, pt q2){
  return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}
//http://www.prefield.com/algorithm/geometry/ccw.html
//与えられた三点 a, b, c を a → b → c と進む
int ccw(_PT a, _PT b, _PT c) {
  _PT bb = b - a, cc = c - a;;
  if (bb.det(cc) > 0)   return +1;       // counter clockwise
  if (bb.det(cc) < 0)   return -1;       // clockwise
  if (bb.dot(cc) < 0)     return +2;       // c--a--b on line
  if (bb.norm() < cc.norm()) return -2;       // a--b--c on line
  return 0;
}
double pdet(pt p1, pt p2){ //pとの外積
  return p1.x * p2.y - p1.x * p2.y;
}

// 線分クラス
typedef struct _LINE{
  pt a, b;
  _LINE(){}
  _LINE(pt x, pt y) : a(x), b(y){
  }
} line;
// http://tomiflu.hatenablog.com/entry/20121209/1355063106
// 2直線の交差判定
bool intersectLL(line &l, line &m) {
  return abs((l.b - l.a).det( m.b - m.a)) > EPS || // 平行ではない
  abs((l.b - l.a).det(m.a - l.a)) < EPS; // 同一直線上(オーバーラップ)
}
// 直線と線分の交差判定
bool intersectLS(line &l, line &s) {
  return (l.b - l.a).det(s.a - l.a) * // s.aはlの左側
  (l.b - l.a).det(s.b - l.a) < EPS; // s.bはlの右側
}
// 直線と点の交差判定
bool intersectLP(line &l, pt &p) {
  return abs((l.b - p).det(l.a - p)) < EPS;
}
// 2線分の交差判定
bool intersectSS(const line &s, const line &t) {
  return ccw(s.a, s.b, t.a)*ccw(s.a,s.b,t.b) <= 0 &&
  ccw(t.a,t.b,s.a)*ccw(t.a,t.b,s.b) <= 0;
}
// 線分と点の交差判定
bool intersectSP(line &s, pt &p) {
  return (s.a - p).abs() + (s.b - p).abs() - (s.b - s.a).abs() < EPS; // 三角不等式
}
//http://www.prefield.com/algorithm/geometry/distance.html
pt projection(line &l, pt &p) {
  double t = (p-l.a).dot(l.a-l.b) / (l.a-l.b).norm();
  return l.a + (l.a - l.b)*t;
}
pt reflection(line &l, pt &p) {
  return p + ((projection(l, p) - p) * 2);
}
double distanceLP(line &l, pt &p) {
  return (p - projection(l, p)).abs();
}
double distanceLL(line &l, line &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m.a);
}
double distanceLS(line &l, line &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s.a), distanceLP(l, s.b));
}
//線分と点の距離
double distanceSP(line &s, pt &p) {
  pt r = projection(s, p);
  if (intersectSP(s, r)) return (r - p).abs();
  return fmin((s.a - p).abs(), (s.b - p).abs());
}
double distanceSS(line &s, line &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t.a), distanceSP(s, t.b)),
  min(distanceSP(t, s.a), distanceSP(t, s.b)));
}
//二直線の交点
pt crosspoint(line &l, line &m) {
  double A = (l.b - l.a).det(m.b - m.a);
  double B = (l.b - l.a).det(l.b - m.a);
  if (abs(A) < EPS && abs(B) < EPS) return m.a; // same line
  // if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m.a + (m.b - m.a) * (B/A);
}



// http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ACAC003&pid=B
void acac003_b(){
  int q, x1, x2, x3, x4, y1, y2, y3, y4;
  line s1, s2;
  cin >> q;
  rep(i, 0, q){
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    s1 = line(pt(x1, y1), pt(x2, y2));
    s2 = line(pt(x3, y3), pt(x4, y4));
    cout << intersectSS(s1, s2) << endl;
  }

}

int main() {
  //doIt();
  return 0;
}
