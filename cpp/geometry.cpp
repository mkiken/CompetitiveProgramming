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


class Triangle{

private:
  //三角形の3点の座標
  p a, b, c;
  //三角形の3辺の長さ
  double ab, bc, ca;
  //三角形の3角の大きさ(ラジアン)
  //double A, B, C;
  double cosA, cosB, cosC, sinA, sinB, sinC;

public:
  //コンストラクタ(3つの点と辺と角度を初期化)
  Triangle(p p1, p p2, p p3){
	a = p1;
	b = p2;
	c = p3;
	ca = abs(c-a);
	bc = abs(b-c);
	ab = abs(a-b);
	cosA = getCosine(p2 - p1, p3 - p1);
	cosB = getCosine(p1 - p2, p3 - p2);
	cosC = getCosine(p1 - p3, p2 - p3);
	sinA = getSine(p2 - p1, p3 - p1);
	sinB = getSine(p1 - p2, p3 - p2);
	sinC = getSine(p1 - p3, p2 - p3);
  }

  //p1とp2の内積
  double dot(p p1, p p2){
	return p1.X*p2.X + p1.Y*p2.Y;
  }

  //p1とp2の外積
  double det(p p1, p p2){
	return p1.X*p2.Y - p2.X*p1.Y;
  }

  //3点が一直線上だったら三角形ではない
  bool isTriangle(){
	double t = det(a - c, b - c);
	return abs(t) < EPS? false : true;
  }

  //余弦定理からcosを求める関数
  double LawOfCosines(double a,double b, double c){
	return (b*b+c*c-a*a) / (2.0*b*c);
  }
  //外積からsineを求める
  double getSine(p p1, p p2){
	return abs(det(p1, p2) / (abs(p1)*abs(p2)));
  }
  //内積からcosineを求める
  double getCosine(p p1, p p2){
	return dot(p1, p2) / (abs(p1)*abs(p2));
  }

  //double circumscribedCircleRadius(){//外接円の半径を返す
  double getCR(){
	return ( bc / (2*sinA));
  }
  //p circumscribedCircle(){//外心(外接円の中心)の座標を返す
  //http://www.h6.dion.ne.jp/~jpe02_tn/ki-5.html
  p getCC(){ // get a circumcenter
	int a1 = 2*(b.X-a.X);
	int b1 = 2*(b.Y-a.Y);
	int c1 = a.X*a.X - b.X*b.X + a.Y*a.Y - b.Y*b.Y;
	int a2 = 2*(c.X-a.X);
	int b2 = 2*(c.Y-a.Y);
	int c2 = a.X*a.X - c.X*c.X + a.Y*a.Y - c.Y*c.Y;

	double x = (b1*c2 - b2*c1)*1.0 / (a1*b2 - a2*b1);
	double y = (c1*a2 - c2*a1)*1.0 / (a1*b2 - a2*b1);
	return p(x, y);
  }

  //http://www004.upp.so-net.ne.jp/s_honma/urawaza/area2.htm
  double getArea(){
	double s = 0;
	s += (a.X - b.X) * (a.Y + b.Y);
	s += (b.X - c.X) * (b.Y + c.Y);
	s += (c.X - a.X) * (c.Y + a.Y);
	return fabs(s) * 0.5;
  }
};

// 円クラス
class Circle{

private:
  //中心座標
  p c;
  //半径
  double r;

public:
  //コンストラクタ(3つの点と辺と角度を初期化)
  Circle(p center, double radius){
	c = center;
	r = radius;
  }

  //aは円の領域内（線上含む）か？
  bool inRegion(p a){
	return (a.X-c.X)*(a.X-c.X)+(a.Y-c.Y)*(a.Y-c.Y) <= r*r + EPS? true : false;
  }
};

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



class Polygon{

private:

public:
  vector<pt> pts;
  int n;
  Polygon(){}
  Polygon(vector<pt> v){
	n = v.size();
	pts = v;
  }
  //凸包（蟻本ver）
  vector<pt> convex_hull(){
	vector<pt> qs(n * 2);
	int k = 0;
	vsort(pts);
	rep(i, 0, n){ //下側凸包の作成
	  while(k > 1 && (qs[k-1] - qs[k-2]).det(pts[i] - qs[k-1]) <= 0) k--;
	  qs[k++] = pts[i];
	}
	for(int i = n - 2, t = k; i >= 0; i--){ //上側凸包の作成
	  while(k > t && (qs[k-1] - qs[k-2]).det(pts[i] - qs[k-1]) <= 0) k--;
	  qs[k++] = pts[i];
	}
	qs.resize(k-1);
	n = k-1;
	pts = qs;
	return qs;
  }

  //点が図形を構成する順番に並んでないと駄目。並んでなければconvex_hullで矯正してから
   double getArea(){
	double s = 0;
	rep(i, 0, n-1) s += pts[i].det(pts[i+1]);
	s += pts[n-1].det(pts[0]);
	return fabs(s) * 0.5;
   }

  //http://www004.upp.so-net.ne.jp/s_honma/urawaza/area2.htm
  double _getArea(){
	double s = 0;
	rep(i, 0, n-1) s += (pts[i].x - pts[i+1].x) * (pts[i].y + pts[i+1].y);
	s += (pts[n-1].x - pts[0].x) *( pts[n-1].y + pts[0].y);
	return fabs(s) * 0.5;
  }

  //http://imagingsolution.net/math/calc_n_point_area/
  //点が時計回りか反時計回りに並んでないと駄目
  double getArea2(){
	double s = 0;
	rep(i, 0, n-1) s += pts[i].x * pts[i+1].y + pts[i+1].x * pts[i].y;
	s += pts[n-1].x * pts[0].y + pts[0].x * pts[n-1].y;
	return fabs(s) * 0.5;
  }

};



//AOJ0010
void aoj0010(){
  int n;
  double x1, y1, x2, y2, x3, y3, px, py, r;
  cin >> n;
  while(n--){
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Triangle t = Triangle(p(x1, y1), p(x2, y2), p(x3, y3));
	p cc = t.getCC();
	printf("%.3f %.3f %.3f\n", cc.X, cc.Y, t.getCR());
  }
}

void area_test(){
  vector<pt> v;
  v.push_back(pt(0, 0));
  v.push_back(pt(0, 1));
  v.push_back(pt(1, 1));
  v.push_back(pt(2, 0));
  v.push_back(pt(1, -1));
  do{
	Polygon p = Polygon(v);
	//cout << p.getArea() << endl;
	p.convex_hull();
	rep(i, 0, p.pts.size()){
	  printf("%f %f\n" , p.pts[i].x, p.pts[i].y);
	}
	printf("s = %f, n = %d\n", p._getArea(), p.n);
  }while(next_permutation(v.begin(), v.end()));

}

void doIt(){
  Triangle t = Triangle(p(0, 1), p(1, 2), p(2, 3));
  cout << t.isTriangle() << endl;
}

int main() {
  //doIt();
  area_test();
  return 0;
}
