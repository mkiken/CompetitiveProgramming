#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;

#include <complex>
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
  //http://www.blackpawn.com/texts/pointinpoly/
  //線分abから見てp1, p2は同じ方向にあるか？
  bool SameSide(p p1, p p2, p a, p b){
    p cp1 = det(b-a, p1-a);
    p cp2 = det(b-a, p2-a);
    if (dot(cp1, cp2) >= 0) return true;
    else return false;
  }
  //点p0がa, b, cからなる三角形の内部にあるか？
  bool _PointInTriangle(p p0, p a, p b, p c){
    if (SameSide(p0,a, b,c) && SameSide(p0,b, a,c)
    && SameSide(p0,c, a,b)) return true;
    else return false;
  }
  bool PointInTriangle(p p0){
    return _PointInTriangle(p0, a, b, c);
  }

};

//AOJ0010
void aoj0010(){
  int n;
  double x1, y1, x2, y2, x3, y3;
  cin >> n;
  while(n--){
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Triangle t = Triangle(p(x1, y1), p(x2, y2), p(x3, y3));
    p cc = t.getCC();
    printf("%.3f %.3f %.3f\n", cc.X, cc.Y, t.getCR());
  }
}

void doIt2(){
  Triangle t = Triangle(p(0, 1), p(1, 2), p(2, 3));
  cout << t.isTriangle() << endl;
}

void solve(){

}

int main(){
  solve();
  return 0;
}
