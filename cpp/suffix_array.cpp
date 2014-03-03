#include <iostream>
#include <cstdio>
#include <cstdlib>
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
#define mrep(i, e, t1, t2) for(map<t1, t2>::iterator i = e.begin(); i != e.end(); i++)
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

//Suffix Array
//http://www.stanford.edu/class/cs97si/suffix-array.pdf
//http://discuss.codechef.com/questions/18105/mou1h-editorial

#define MAX_N 100005
#define MAXLG 18
#define MIN_VALUE -INF
struct entry {
  int nr[2], p;

  bool operator <(const struct entry &e) const{
    return nr[0] == e.nr[0] ? (nr[1] == e.nr[1]? p < e.p : nr[1] < e.nr[1]) : (nr[0] < e.nr[0]);
  }
  bool operator >(const struct entry &e) const{
    return nr[0] == e.nr[0] ? (nr[1] == e.nr[1]? p > e.p : nr[1] > e.nr[1]) : (nr[0] > e.nr[0]);
  }
} L[MAX_N];
int SA[MAXLG][MAX_N], N, suffix[MAX_N], LCP[MAX_N];

//SA[k][i] : the order of the subsequence of A of length 2^k starting at position i.
//return the last row of matrix SA
// O(N (logN)^2)
int makeSuffixArray(string A) {
  int stp = 1, cnt = 1;
  N = A.length();
  Rep(i, N) SA[0][i] = A[i] - 'a';
  while(cnt < N){
    Rep(i, N){
      L[i].nr[0] = SA[stp - 1][i];
      L[i].nr[1] = (i + cnt < N)? SA[stp - 1][i + cnt] : MIN_VALUE;
      L[i].p = i;
    }
    sort(L, L + N);
    Rep(i, N){
      SA[stp][L[i].p] = (i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1])? SA[stp][L[i - 1].p] : i;
    }
    stp++;
    cnt *= 2;
  }
  return stp-1;
}

//Computing the longest common prefix (LCP)
// O(log N)
int lcp(int x, int y, int stp)
{
  int k, ret = 0;
  if (x == y) return N - x;
  for (int k = stp; k >= 0 && x < N && y < N; k--){
    if (SA[k][x] == SA[k][y]){
      x += (1 << k);
      y += (1 << k);
      ret += (1 << k);
    }
  }
  return ret;
}

//結果はsuffixに格納．
int getSuffixArray(string str){
  int idx = makeSuffixArray(str);
  vector<P> v;
  Rep(i, N){
    suffix[SA[idx][i]] = i;
  }
  return idx;
}

//結果はLCPに格納
void getLCPArray(int stp){
  LCP[0] = 0;
  rep(i, 1, N){
    LCP[i] = lcp(suffix[i-1], suffix[i], stp);
  }
}

void doIt(){
  string s = "mississippi";
  // string s = "bcba";
  int idx = getSuffixArray(s);
  Rep(i, N){
    printf("%d ", suffix[i]);
  }
  printf("\n");
  getLCPArray(idx);
  rep(i, 0, N){
    // cout << lcp(suffix[i-1], suffix[i]) << endl;
    cout << LCP[i] << endl;
  }

}

int main() {
  doIt();
  return 0;
}
