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
typedef vector<int> VI;
typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

// const int INF = (int)2e9;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;

#define MAX_N 100 + 2

class StarrySkyTree{
protected:

  const static int SIZE = 1 << 17;
  ll seg[SIZE * 2 + 2], segAdd[SIZE * 2 + 2];
  int size;

  // 木の子から親を定義する関数
  virtual ll _func(ll a, ll b) = 0;

  // 木のインデックス範囲外の時に返すデフォルト値
  virtual ll _getDefaultValue() = 0;

  void _add(int a, int b, int x, int k, int l, int r){
    if (r <= a || b <= l) return;
    if (a <= l && r <= b){
      segAdd[k] += x;
      while (k){
        k = (k - 1) / 2;
        seg[k] = _func(seg[k * 2 + 1] + segAdd[k * 2 + 1], seg[k * 2 + 2] + segAdd[k * 2 + 2]);
      }
      return;
    }
    _add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    _add(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }

  ll _get(int a, int b, int k, int l, int r){
    if (r <= a || b <= l) return _getDefaultValue();
    if (a <= l && r <= b) return (seg[k] + segAdd[k]);
    ll left = _get(a, b, k * 2 + 1, l, (l + r) / 2);
    ll right = _get(a, b, k * 2 + 2, (l + r) / 2, r);
    return _func(left, right) + segAdd[k];
  }

public:
  StarrySkyTree(int n){
    assert(n <= SIZE);
    size = n;
  }

  /**
  * 区間[a, b]に値xを加算する.
  * sizeは木の要素数
  */
  void add(int a, int b, int x){
    _add(a, b+1, x, 0, 0, size+1);
  }

  /**
  * 区間[a, b]の最小値を取得.
  * sizeは木の要素数
  */
  ll get(int a, int b){
    return _get(a, b+1, 0, 0, size+1);
  }

};

class StarrySkyTreeMin : public StarrySkyTree {
  using StarrySkyTree::StarrySkyTree;
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

class StarrySkyTreeMax : public StarrySkyTree {
  using StarrySkyTree::StarrySkyTree;
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


void execMin(){
  int n = 10;
  int diff = -5;
  StarrySkyTreeMin sst = StarrySkyTreeMin(n);
  for (int i = 0; i < n; i++){
    sst.add(i, i, i - diff);
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
  StarrySkyTreeMax sst = StarrySkyTreeMax(n);
  for (int i = 0; i < n; i++){
    sst.add(i, i, i - diff);
  }

  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j++){
      ll tmp = sst.get(i, j);
      assert(tmp == j - diff);
      printf("[%d, %d] = %lld\n", i, j, tmp);
    }
  }

}

void exec(){
  execMin();
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
  return 0;
}
