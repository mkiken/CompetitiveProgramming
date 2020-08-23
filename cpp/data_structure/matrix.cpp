#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef tuple<int, int, int> ituple;

const int INF = INT_MAX;
// const ll INF = LLONG_MAX;
// const int MOD = ((int)1e9 + 7);
const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (200000 + 2)

template <class T, int H, int W = H> class Matrix2D {
public:
  int h,w;
  array<array<T,W>,H> a;
  Matrix2D():h(H),w(W){
    // do nothing
  }
  Matrix2D(const vector<vector<T>>& vec):h(H),w(W) {
    assert(vec.size()==H && vec.front().size()==W);
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=vec[i][j];
  }
  static Matrix2D identity() {
    assert(H==W);
    Matrix2D res = Matrix2D();
    for(int i = 0; i < H; ++i) res[i][i]=1;
    return res;
  }
  Matrix2D &operator+=(const Matrix2D &r) {
    assert(H==r.h&&W==r.w);
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r[i][j];
    return *this;
  }
  Matrix2D &operator-=(const Matrix2D &r) {
    assert(H==r.h&&W==r.w);
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]-=r[i][j];
    return *this;
  }
  Matrix2D &operator*=(const Matrix2D &r) {
    assert(W==r.h);
    Matrix2D res = Matrix2D();
    for(int i = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res[i][j]+=(a[i][k])*(r[k][j]);
    a.swap(res.a);
    return *this;
  }
  Matrix2D operator+(const Matrix2D& r) const {
    return Matrix2D(*this) += r;
  }
  Matrix2D operator-(const Matrix2D& r) const {
    return Matrix2D(*this) -= r;
  }
  Matrix2D operator*(const Matrix2D& r) const {
    return Matrix2D(*this) *= r;
  }
  inline array<T,W> &operator[](int i) {
    return a[i];
  }
  inline const array<T,W> &operator[](int i) const {
    return a[i];
  }
  Matrix2D pow(ll K) const {
    assert(H == W);
    Matrix2D x(*this);
    Matrix2D res = this->identity();
    for (; K > 0; K /= 2) {
      if (K & 1) res *= x;
      x *= x;
    }
    return res;
  }

  /**
  ** 行列式
  ** O(n^3)
  ** 除算が含まれているので、Tを適切に指定すること
  */
  T determinant(void) const {
    assert(H==W);
    Matrix2D x(*this);
    T res = 1;
    for(int i = 0; i < H; i++) {
      int idx = -1;
      for(int j = i; j < W; j++) if(x[j][i] != 0) idx = j;
      if(idx == -1) return 0;
      if(i != idx) {
        res *= -1;
        swap(x[i], x[idx]);
      }
      res *= x[i][i];
      T tmp = x[i][i];
      for(int j = 0; j < W; ++j) x[i][j] /= tmp;
      for(int j = i + 1; j < H; j++) {
        tmp = x[j][i];
        for(int k = 0; k < W; k++) x[j][k] -= x[i][k]*tmp;
      }
    }
    return res;
  }
};


void testDet() {
  assert((Matrix2D<ld, 3>(
    {
      {1, 1, 0},
      {1, 0, 1},
      {0, 1, 1},
    }
  ).determinant()) == -2);

  assert((Matrix2D<ld, 3>(
    {
      {1, 1, 0},
      {1, 1, 1},
      {0, 1, 1},
    }
  ).determinant()) == -1);

  assert((Matrix2D<ld, 2>(
    {
      {0, 0},
      {0, 0},
    }
  ).determinant())== 0);

  assert((Matrix2D<ld, 12>(
    {
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
      {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
      {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
      {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    }
  ).determinant())== 0);

  printf("testGet passed.\n");
}

void exec(){
  testDet();
}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  // test();
  return 0;
}
