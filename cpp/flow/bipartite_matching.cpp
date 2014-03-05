#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
//#include <stack>
//#include <limits>
#include <sstream>
//#include <functional>
#include <complex>

using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
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
#define X real()
#define Y imag()
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef complex<double> p;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;


//二部マッチング（蟻本）

#define MAX_V 2001
int V; //頂点数
vector<int> G[MAX_V]; //グラフの隣接リスト表現
int match[MAX_V]; //マッチングのペア（-1で初期化）
bool used[MAX_V]; //DFSのフラグ

//uとvを結ぶ
void add_edge(int v, int u){
  G[u].push_back(v);
  G[v].push_back(u);
}

//増加パスをDFSで探す
bool dfs(int v){
  used[v] = true;
  rep(i, 0, G[v].size()){
	int u = G[v][i], w = match[u];
	if(w < 0 || (!used[w] && dfs(w))){
	  match[u] = v;
	  match[v] = u;
	  return true;
	}
  }
  return false;
}

int bipartite_matching(){
  int res = 0;
  afill(match, -1);
  rep(v, 0, V){
	if(match[v] < 0){
	  afill(used, false);
	  if(dfs(v)) res++;
	}
  }
  return res;
}


void doIt(){
  int t, n, x, y, nx, ny, px, py;
  map<int, int> xx, yy;
  cin >> t;
  while(t--){
	cin >> n;
	xx.clear();
	yy.clear();
	nx = ny = 0;

	rep(i, 0, n){
	  cin >> x >> y;
	  if(xx.count(x) == 0){
		px = nx;
		xx[x] = nx++;
	  }
	  else px = xx[x];
	  if(yy.count(y) == 0){
		py = ny;
		yy[y] = ny++;
	  }
	  else py = yy[y];
	  add_edge(px, py + n);
	}
	V = 2*n;
	cout << bipartite_matching() << endl;
	rep(i, 0, 2*n) G[i].clear();
  }
}

int main() {
  doIt();
  return 0;
}
