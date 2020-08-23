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

class Matrix2D {
protected:
  int N, M;
  vector<vector<ld>> data;

public:
  Matrix2D(int n, int m) {
    N = n;
    M = m;
    data.assign(n, vector<ld>(m));
  }

  Matrix2D(vector<vector<ld>> v) {
    N = v.size();
    M = v[0].size();
    data = v;
  }

  int getN() const {
    return N;
  }

  int getM() const {
    return M;
  }

  void setValue(int n, int m, ld value) {
    data[n][m] = value;
  }

  ld getValue(int n, int m) const {
    return data[n][m];
  }

  void swapRow(int n1, int n2) {
    swap(data[n1], data[n2]);
  }

  Matrix2D clone() {
    Matrix2D A = Matrix2D(getN(), getM());
    for (int i = 0; i < getN(); i++){
      for (int j = 0; j < getM(); j++){
        A.setValue(i, j, getValue(i, j));
      }
    }

    return A;
  }

  /**
  ** O(n^3)
  */
  Matrix2D multiply(const Matrix2D &B) {
    Matrix2D C(getN(), B.getM());
    for (int i = 0; i < getN(); ++i)
    for (int j = 0; j < getM(); ++j)
    for (int k = 0; k < getM(); ++k)
    C.setValue(i, j, C.getValue(i, j) + data[i][k] * B.getValue(k, j));

    return C;
  }

  /**
  ** 行列式
  ** O(n^3)
  */
  ld det() {
    Matrix2D A = clone();

    const int n = getN();
    ld D = 1;
    for (int i = 0; i < n; ++i) {
      int pivot = i;
      for (int j = i+1; j < n; ++j)
      if (abs(A.getValue(j, i)) > abs(A.getValue(pivot, i))) pivot = j;
      A.swapRow(pivot, i);
      D *= A.getValue(i, i) * (i != pivot ? -1 : 1);
      if (abs(A.getValue(i, i)) < EPS) break;
      for(int j = i+1; j < n; ++j)
      for(int k = n-1; k >= i; --k)
      A.setValue(j, k, A.getValue(j, k) - (A.getValue(i, k) * A.getValue(j, i) / A.getValue(i, i)));
    }
    return D;
  }

  /**
  ** 累乗
  ** O(n^3 log e)
  */
  Matrix2D pow(int e) {
    if (e == 0) {
      return Matrix2D::identity(getN());
    }

    Matrix2D A = clone();
    return e % 2 == 0 ? A.multiply(A).pow(e / 2) : A.multiply(A.pow(e - 1));
  }

  /**
  ** O(n)
  */
  ld tr() {
    ld ans = 0;
    for (int i = 0; i < getN(); ++i)
    ans += getValue(i, i);
    return ans;
  }

  /**
  ** O(n^3)
  */
  int rank() {
    Matrix2D A = clone();
    const int n = getN(), m = getM();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
      int pivot = r;
      for (int j = r+1; j < n; ++j) if (abs(A.getValue(j, i)) > abs(A.getValue(pivot, i))) pivot = j;
      A.swapRow(pivot, r);
      if (abs(A.getValue(r, i)) < EPS) continue;
      for (int k = m-1; k >= i; --k) {
        A.setValue(r, k, A.getValue(r, k) / A.getValue(r, i));
      }
      for(int j = r+1; j < n; ++j)
      for(int k = i; k < m; ++k) {
        A.setValue(j, k, A.getValue(j, k) - A.getValue(r, k) * A.getValue(j, i));
      }
      ++r;
    }
    return r;
  }

  void debugPrint() {
    cout << "------------------------" << endl;
    for (int i = 0; i < getN(); i++){
      printf("%2d: ", i);
      for (int j = 0; j < getM(); j++){
        printf("%.2Lf%c", getValue(i, j), j == getM() - 1 ? '\n' : ' ');
      }
    }
    cout << "------------------------\n" << endl;
  }

  /**
  ** 単位行列
  */
  static Matrix2D identity(int n)
  {
    Matrix2D m = Matrix2D(n, n);
    for (int i = 0; i < n; i++){
      m.setValue(i, i, 1);
    }

    return m;
  }
};

void testDet() {
  assert(Matrix2D(
    {
      {1, 1, 0},
      {1, 0, 1},
      {0, 1, 1},
    }
  ).det()== -2);

  assert(Matrix2D(
    {
      {1, 1, 0},
      {1, 1, 1},
      {0, 1, 1},
    }
  ).det()== -1);

  assert(Matrix2D(
    {
      {0, 0},
      {0, 0},
    }
  ).det()== 0);

  assert(Matrix2D(
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
  ).det()== 0);

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
