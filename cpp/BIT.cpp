//#include <iostream>
//#include <cmath>
//#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i,a) for(int i = 0;i < a;i++)
#define mfill(a, v) fill(a, a + len(a), v)
const double EPS = 1e-10;

const int MAX_N = 100000 + 2;
ll bit0[MAX_N];
ll bit1[MAX_N];


void add(int idx, ll val, ll* ary){
  int p = idx;
  while(p < MAX_N){
	ary[p] += val;
	p += p & -p;
  }
}

void badd(int l, int r, ll val){
  add(l, -val * (l - 1), bit0);
  add(l, val, bit1);
  add(r + 1, r * val, bit0);
  add(r + 1, -val, bit1);
}


ll sum(int idx, ll *ary){
  ll res = 0;
  int p = idx;
  while(0 < p){
	res += ary[p];
	p -= p & -p;
  }
  return res;
}

ll ssum(int idx){
  return sum(idx, bit1) * idx + sum(idx, bit0);
}

void doIt(){
  mfill(bit0, 0);
  mfill(bit1, 0);
}

int main() {
  doIt();
  return 0;
}
