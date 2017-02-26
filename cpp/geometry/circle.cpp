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
#define X real()
#define Y imag()
typedef complex<double> p;

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

void solve(){

}

int main(){
  solve();
  return 0;
}
