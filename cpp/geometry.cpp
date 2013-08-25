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

  //3点が一直線上だったら三角形ではない
  bool isTriangle(){
	double t = det(a - c, b - c);
	return abs(t) < EPS? false : true;
  }
  //p1とp2の内積
  double dot(p p1, p p2){
	return p1.X*p2.X + p1.Y*p2.Y;
  }
  //p1とp2の外積
  double det(p p1, p p2){
	return p1.X*p2.Y - p2.X*p1.Y;
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

void doIt(){
  Triangle t = Triangle(p(0, 1), p(1, 2), p(2, 3));
  cout << t.isTriangle() << endl;
}

int main() {
  doIt();
  return 0;
}
