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
#define MAX_N 16

//http://www.mwsoft.jp/programming/java/java_lang_integer_bit_count.html
int bitcount(int i){
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0f0f0f0f;
  i = i + (i >> 8);
  i = i + (i >> 16);
  return i & 0x3f;
}



void doIt(){
  int n, e, dist[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];
  cin >> n;
  rep(i, 0, n){
	rep(j, i+1, n){
	  cin >> e;
	  dist[i][j] = dist[j][i] = e;
	}
  }
  afill2(dp, INF, int);
  dp[(1 << n) - 1][0] = 0;
  Rrep(S, (1 << n) - 2){
	rep(v, 0, n){
	  rep(u, 0, n){
		if(!(S >> u & 1)){
		  dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + dist[v][u]);
		}
	  }
	}
  }
  if(n == 2) cout << 0 << " " << 0 << endl;
  else cout << n << " " << dp[0][0] << endl;
}

// http://maximum-cup-2013.contest.atcoder.jp/tasks/maximum_2013_a
int main() {
  doIt();
  return 0;
}
