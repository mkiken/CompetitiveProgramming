#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <sstream>
#include <functional>
#include <complex>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define Rep(i, e) for(int i = 0;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define Rrep(i, e) for(int i = e;0 <= i;i--)
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
#define pb push_back
#define rg(i, s, t) s <= i && i < t
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;

/*
  xor Binary Indexed Tree
*/
class BitXor{
protected:
  static const int max_value = 100000 + 2;
  ll bit[max_value + 1];

public:
  BitXor(int size) {
    assert(size < max_value);
    init();
  }
  void init(){
    for (int i = 0; i < max_value; i++){
      bit[i] = 0;
    }
  }
  void add(int idx, ll val){
    int p = idx+1;
    while(p < max_value){
      bit[p] ^= val;
      p += p & -p;
    }
  }
  /**
   * [0, idx]のxorを求める
   */
  ll calc(int idx){
    ll res = 0;
    int p = idx+1;
    while(0 < p){
      res ^= bit[p];
      p -= p & -p;
    }
    return res;
  }
  /**
   * [idx1, idx2]のxorを求める
   */
  ll range(int idx1, int idx2) {
    return calc(idx2) ^ calc(idx1 - 1);
  }
};

void doIt(){
  BitXor bx = BitXor(100);
  bx.add(1, 10);
  bx.add(2, 20);
  bx.add(3, 30);

  assert(bx.calc(0) == 0);
  assert(bx.calc(1) == (10));
  assert(bx.calc(2) == (10 ^ 20));
  assert(bx.calc(3) == (10 ^ 20 ^ 30));

  assert(bx.range(0, 0) == 0);
  assert(bx.range(0, 1) == 10);
  assert(bx.range(0, 3) == (10 ^ 20 ^ 30));
  assert(bx.range(1, 1) == 10);
  assert(bx.range(1, 2) == (10 ^ 20));
  assert(bx.range(2, 3) == (20 ^ 30));
  assert(bx.range(1, 3) == (10 ^ 20 ^ 30));
}

int main() {
  doIt();
  return 0;
}
