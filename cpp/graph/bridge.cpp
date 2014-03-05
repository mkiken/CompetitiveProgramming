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

const int MAX_N = 100002, MAX_M = 100002, WHITE = 0, GRAY = 1, BLACK = 2;
int color[MAX_N], low[MAX_N], pred[MAX_N], d[MAX_N], ttime = 0;
bool used[MAX_M];
vector<int> edge[MAX_N];
vector<int> bridge;
map<ll, int> tab;
ll hash(ll a, ll b) {
  if (a <= b) return a * MAX_N + b;
  else return b * MAX_N + a;
}
void init(){
  ttime = 0;
  afill(color, WHITE);
  afill(low, INF);
  afill(pred, -1);
  afill(d, -1);
  afill(used, false);
  rep(i, 0, len(edge)) edge[i].clear();
  bridge.clear();
  tab.clear();
}
void dfs(int v){
  color[v] = GRAY;
  low[v] = d[v] = ++ttime;
  rep(i, 0, edge[v].size()){
	int w = edge[v][i];
	if(color[w] == WHITE){
	  pred[w] = v;
	  dfs(w);
	  if(low[w] > d[v]){
		int t = tab[hash(v,w)];
		if(t != -1 && used[t] == false){
		  bridge.push_back(t);
		  used[t] = true;
		}
	  }
	  low[v] = min(low[v], low[w]);
	}
	else if(w != pred[v]) low[v] = min(low[v], d[w]);
  }
  color[v] = BLACK;
}
// http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ACAC003&pid=D
void doIt(){
  int v, e, s, t;
  ll h;
  P es[MAX_N];
  vector<P> ans;
  cin >> v >> e;
  init();
  rep(i, 0, e){
	cin >> s >> t;
	edge[s].push_back(t);
	edge[t].push_back(s);
	es[i] = P(s, t);
	h = hash(s,t);
	if (tab.count(h) == 0) tab[h] = i;
	else tab[h] = -1;
  }
  dfs(0);
 rep(i, 0, bridge.size()){
   P ele = es[bridge[i]];
   ans.push_back(P(fmin(ele.first, ele.second), fmax(ele.first, ele.second)));
 }
 vsort(ans);
rep(i, 0, ans.size()){
  printf("%d %d\n", ans[i].first, ans[i].second);
 }
}

int main() {
  doIt();
  return 0;
}
