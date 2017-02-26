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

#include <cmath>

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
  _PT operator / (double d){
    return _PT(x/d, y/d);
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

class Polygon{
private:
public:
  vector<pt> pts;
  int n;
  // 点が順番に並んでいるか
  bool isAlign;
  Polygon(){}
  Polygon(vector<pt> v){
    n = v.size();
    pts = v;
    isAlign = false;
  }

// 点が多角形の内部にあるかどうか
//点が図形を構成する順番に並んでないと駄目。並んでなければconvex_hullで矯正してから
// @param {pt} p 判定したい点
// @param {bool} aligned すでに頂点が整列されてるかどうか
// @return {int} 外部なら1、線上なら0、-1なら内部
// http://www.sousakuba.com/Programming/gs_hittest_point_triangle.html
  int contains(pt p, bool aligned = false){
    if (!aligned && !isAlign){
      return -INF;
    }
    bool isOn = false;
    int sign = 0;
    bool isOk = true;

    for (int i = 0; i < n; i++){
      pt b = pts[(i + 1) % n];
      pt a = pts[i];
      pt ba = b - a;
      pt bp = p - b;
      double cross = ba.det(bp);
      if (abs(cross) < EPS){
        isOn = true;
      }
      else{
        if (sign == 0){
          sign = cross < 0 ? -1 : 1;
        }
        else{
          if (sign * cross < 0){
            isOk = false;
            break;
          }
        }
      }
    }
    if (!isOk){
      return 1;
    }
    if (isOn){
      return 0;
    }
    return -1;
  }

  //凸包（蟻本ver）
  vector<pt> convex_hull(){
    vector<pt> qs(n * 2);
    int k = 0;
    sort(pts.begin(), pts.end());
    for (int i = 0; i < n; i++){ //下側凸包の作成
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
    isAlign = true;
    return qs;
  }

  //点が図形を構成する順番に並んでないと駄目。並んでなければconvex_hullで矯正してから
  double getArea(){
    double s = 0;
    for (int i = 0; i < n-1; i++) s += pts[i].det(pts[i+1]);
    s += pts[n-1].det(pts[0]);
    return (s < 0 ? -s : s) * 0.5;
  }
  //http://www004.upp.so-net.ne.jp/s_honma/urawaza/area2.htm
  double _getArea(){
    double s = 0;
    for (int i = 0; i < n-1; i++) s += (pts[i].x - pts[i+1].x) * (pts[i].y + pts[i+1].y);
    s += (pts[n-1].x - pts[0].x) *( pts[n-1].y + pts[0].y);
    return (s < 0 ? -s : s) * 0.5;
  }
  //http://imagingsolution.net/math/calc_n_point_area/
  //点が時計回りか反時計回りに並んでないと駄目
  double getArea2(){
    double s = 0;
    for (int i = 0; i < n-1; i++) s += pts[i].x * pts[i+1].y + pts[i+1].x * pts[i].y;
    s += pts[n-1].x * pts[0].y + pts[0].x * pts[n-1].y;
    return (s < 0 ? -s : s) * 0.5;
  }
  //キャリパー法で最遠点対を求める。要convex_hull
  double maxDist(){
    vector<pt> qs = pts;
    double res = 0;
    if(n == 2) return qs[0].dist(qs[1]);
    int i = 0, j = 0;
    for (int k = 0; k < n; k++){
      if(qs[i] > qs[k]) i = k;
      if(qs[j] < qs[k]) j = k;
    }
    int si = i, sj = j;
    while(i != sj || j != si){
      res = max(res, qs[i].dist(qs[j]));
      if((qs[(i+1) % n] - qs[i]).det(qs[(j+1) % n] - qs[j]) < 0) i = (i + 1) % n;
      else j = (j + 1) % n;
    }
    return res;
  }
};

void containTest(){
  vector<pt> v;
  v.push_back(pt(0, 0));
  v.push_back(pt(0, 1));
  v.push_back(pt(1, 1));
  v.push_back(pt(1, 0));
  Polygon p = Polygon(v);

  cout << p.contains(pt(0, 0), true) << endl;
  cout << p.contains(pt(0, 0.5), true) << endl;
  cout << p.contains(pt(0.5, 0.5), true) << endl;
  cout << p.contains(pt(2, 2), true) << endl;

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
    for (int i = 0; i < p.pts.size(); i++){
      printf("%f %f\n" , p.pts[i].x, p.pts[i].y);
    }
    printf("s = %f, n = %d\n", p._getArea(), p.n);
  }while(next_permutation(v.begin(), v.end()));

}

// http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ACAC002&pid=C
void test(){
  int n;
  vector<pt> v;
  double x, y;
  Polygon pl;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x >> y;
    v.push_back(pt(x, y));
  }
  pl = Polygon(v);
  pl.convex_hull();
  printf("%.9f\n", pl.maxDist());
}

int main() {
  containTest();
  return 0;
}
