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
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (300000 + 2)

class SegmentTree {
protected:
  const static int SIZE = 1 << 18; // 262144
  const static int DATA_SIZE = SIZE * 2 + 2;
  int N;
  ll seg[DATA_SIZE];

  // 木の子から親を定義する関数
  virtual ll _func(ll a, ll b) = 0;

  // 木のインデックス範囲外の時に返すデフォルト値
  virtual ll _getDefaultValue() = 0;

  ll _get(int a, int b, int k, int l, int r) {
    if(r <= a or b <= l) return _getDefaultValue();
    if(a <= l and r <= b) return seg[k];
    int m = (l + r) / 2;
    return _func(_get(a, b, k*2+1, l, m), _get(a, b, k*2+2, m, r));
  }

public:
  SegmentTree(int n) {
    assert(n <= SIZE);
    N = 1;
    while(N < n) N *= 2;
    assert(N <= DATA_SIZE);
    for(int i = 0; i < 2*N-1; i++) {
      seg[i] = 0;
    }
  }

  // k個目の要素をaに更新
  void set(int k, ll a) {
    k += N-1;
    seg[k] = a;
    while(k > 0) {
      k = (k - 1) / 2;
      seg[k] = _func(seg[k*2+1], seg[k*2+2]);
    }
  }

  // 区間[a, b]のクエリ結果を取得
  ll get(int a, int b) {
    int result = _get(a, b+1, 0, 0, N);
    return result;
  }
};

class SegmentTreeMin : public SegmentTree {
  using SegmentTree::SegmentTree;
protected:
  // 木の子から親を定義する関数
  ll _func(ll a, ll b){
    return min(a, b);
  }

  // 木のインデックス範囲外の時に返すデフォルト値
  ll _getDefaultValue(){
    return LLONG_MAX;
  }
};

class SegmentTreeMax : public SegmentTree {
  using SegmentTree::SegmentTree;
protected:
  // 木の子から親を定義する関数
  ll _func(ll a, ll b){
    return max(a, b);
  }

  // 木のインデックス範囲外の時に返すデフォルト値
  ll _getDefaultValue(){
    return LLONG_MIN;
  }
};

class SegmentTreeSum : public SegmentTree {
  using SegmentTree::SegmentTree;
protected:
  // 木の子から親を定義する関数
  ll _func(ll a, ll b){
    return a + b;
  }

  // 木のインデックス範囲外の時に返すデフォルト値
  ll _getDefaultValue(){
    return 0;
  }
};

void execMaxLarge(){
  int n = 200000;
  int diff = -5;
  SegmentTreeMax sst = SegmentTreeMax(n);
  for (int i = 0; i < n; i++){
    sst.set(i, i - diff);
  }

  for (int j = 0; j < n; j++){
    ll tmp = sst.get(0, j);
    assert(tmp == j - diff);
  }
}

void execMinLarge(){
  int n = 200000;
  int diff = -500000;
  SegmentTreeMin sst = SegmentTreeMin(n);
  for (int i = 0; i < n; i++){
    sst.set(i, i - diff);
  }

  for (int i = 0; i < n; i++){
    ll tmp = sst.get(i, n-1);
    if (tmp != i - diff){
      printf("[%d, %d] = %lld\n", i, n-1, tmp);
      assert(tmp == i - diff);
    }
  }
}

void execMin(){
  int n = 10;
  int diff = -5;
  SegmentTreeMin sst = SegmentTreeMin(n);
  for (int i = 0; i < n; i++){
    sst.set(i, i - diff);
  }

  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j++){
      ll tmp = sst.get(i, j);
      assert(tmp == i - diff);
      printf("[%d, %d] = %lld\n", i, j, tmp);
    }
  }

}

void execMax(){
  int n = 10;
  int diff = -5;
  SegmentTreeMax sst = SegmentTreeMax(n);
  for (int i = 0; i < n; i++){
    sst.set(i, i - diff);
  }

  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j++){
      ll tmp = sst.get(i, j);
      assert(tmp == j - diff);
      printf("[%d, %d] = %lld\n", i, j, tmp);
    }
  }
}

void execSum(){
  int n = 10;
  int diff = -5;
  SegmentTreeSum sst = SegmentTreeSum(n);
  for (int i = 0; i < n; i++){
    sst.set(i, i - diff);
  }

  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j++){
      ll tmp = sst.get(i, j);
      printf("[%d, %d] = %lld\n", i, j, tmp);
    }
  }
}
void exec(){
  // execSum();
  // execMax();
  // execMin();
  execMaxLarge();
  execMinLarge();
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
