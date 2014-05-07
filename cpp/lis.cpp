#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define rep(i, s, e) for(int i = (s);i < (e);i++)
#define Rep(i, e) for(int i = 0;i < (e);i++)
#define rrep(i, e, s) for(int i = (e);(s) <= i;i--)
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
#define afill2(a, v, t) fill((t *)(a), (t *)((a) + len(a)), v)
#define fmax(a, b) ((a) < (b)? (b) : (a))
#define fmin(a, b) ((a) > (b)? (b) : (a))
#define fabs(a) ((a) < 0? -(a) : (a))
#define pb push_back
#define fst(e) (e).first
#define snd(e) (e).second
#define rg(e, s, t) (s <= e && e < t)
#define PQDecl(name, tp) priority_queue< tp, vector<tp>, greater<tp> > name
#define dq(q) q.top();q.pop();
#define sz(v) ((int)(v).size())
#define lg(s) ((int)(s).length())
//#define X real()
//#define Y imag()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<int> VI;
//typedef complex<double> p;
const int INF = (int)2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};
typedef struct _Datum {
  int fst,snd,trd;
  _Datum(int arg1 = 0, int arg2 = 0 , int arg3 = 0) {
	fst = arg1; snd = arg2; trd = arg3;
  }
  bool operator <(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd < e.trd : snd < e.snd) : fst < e.fst;
  }
  bool operator >(const struct _Datum &e) const{
    return fst == e.fst? (snd == e.snd? trd > e.trd : snd > e.snd) : fst > e.fst;
  }
}datum;

void printAI(int *a, int n){
    printf("---printAI---\n");
    Rep(i, n) printf("%d%c", a[i], i==n-1?'\n':' ');
    printf("-----------------\n");
}
void printAI2D(int **a, int n, int m){
    printf("---printAI2D---\n");
    Rep(i, n) Rep(j, m) printf("%d%c", a[i][j], j==n-1?'\n':' ');
    printf("-----------------\n");
}
void printVI(const VI &v){
    printf("-----printVI-----\n");
    Rep(i, sz(v)) printf("%d%c", v[i], i==sz(v)-1?'\n':' ');
    printf("-----------------\n");
}

#define MAX_N 100005

// http://stackoverflow.com/questions/4938833/find-longest-increasing-sequence
vector<int> getLIS(const vector<int> &v) {
  int size = v.size(), max_len = 1;
  // M[i] is the index of the last element of the sequence whose length is i
  int *M = new int[size];
  // P[i] is the index of the previous element of i in the sequence, which is used to print the whole sequence
  int *P = new int[size];
  M[0] = 0; P[0] = -1;
  for (int i = 1; i < size; ++i) {
    if (v[i] > v[M[max_len - 1]]) {
      M[max_len] = i;
      P[i] = M[max_len - 1];
      ++max_len;
      continue;
    }
    // Find the position to insert i using binary search
    int lo = 0, hi = max_len - 1;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (v[i] < v[M[mid]]) {
        hi = mid - 1;
      } else if (v[i] > v[M[mid]]) {
        lo = mid + 1;
      } else {
        lo = mid;
        break;
      }
    }
    P[i] = P[M[lo]];  // Modify the previous pointer
    M[lo] = i;
  }
  vector<int> res;
  // Print the whole subsequence
  int i = M[max_len - 1];
  while (i >= 0) {
      res.pb(v[i]);
      i = P[i];
  }
  delete[] M, delete[] P;
  reverse(vrange(res));
  return res;
}

int getLISLength(const VI &v){
    int n = sz(v);
    VI dp(sz(v), INF);
    Rep(i, sz(v)){
        *(lower_bound(dp.begin(), dp.end(), v[i])) = v[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

void doTest() {
  int data[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  vector<int> v;
  v.insert(v.end(), data, data + sizeof(data) / sizeof(int));
  printVI(getLIS(v));
  cout << getLISLength(v) << endl;
}

// http://codeforces.com/contest/340/problem/D
void solve(){
    int n, a[MAX_N];
    VI v;
    cin >> n;
    Rep(i, n){
        scanf("%d", &a[i]);
        v.pb(a[i]);
    }
    cout << getLISLength(v) << endl;
}

void doIt(){
  int t = 1;
  // scanf("%d", &t);
  while(t--){
    solve();
  }
}

int main() {
  doIt();
  return 0;
}
