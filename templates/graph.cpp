#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
//#include <map>
#include <set>
//#include <queue>
//#include <limits>
//#include <sstream>
//#include <functional>
using namespace std;

#define len(array)  (sizeof (array) / sizeof *(array))
#define rep(i, s, e) for(int i = s;i < e;i++)
#define rrep(i, e, s) for(int i = e;s <= i;i--)
#define mfill(a, v) fill(a, a + len(a), v)
#define mfill2(a, v, t) fill((t *)a, (t *)(a + len(a)), v)
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v, t) sort(v.begin(), v.end(), greater<t>())
#define asort(a) sort(a, a + len(a))
#define rasort(a, t) sort(a, a + len(a), greater<t>())
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
const int INF = 10000000;
const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

const int MAX_N = 3005, WHITE = 0, GRAY = 1, BLACK = 2;
int color[MAX_N], low[MAX_N], pred[MAX_N], d[MAX_N], ttime = 0;
vector<int> edge[MAX_N];
set<int> bridge;

// Tarjan's Algorithm for Articulation Points
void dfs(int v){
  int children = 0;
  color[v] = GRAY;
  low[v] = d[v] = ++ttime;
  rep(i, 0, edge[v].size()){
	int w = edge[v][i];
	if(color[w] == WHITE){
	  pred[w] = v;
	  dfs(w);
	  if(v != 0 && low[w] >= d[v]) bridge.insert(v);
	  low[v] = min(low[v], low[w]);
	  children++;
	}
	else if(w != pred[v]) low[v] = min(low[v], d[w]);
  }
  if(v == 0 && 2 <= children) bridge.insert(v);
  color[v] = BLACK;
}
void init(){
  ttime = 0;
  mfill(color, WHITE);
  mfill(low, INF);
  mfill(pred, -1);
  mfill(d, -1);
  rep(i, 0, len(edge)) edge[i].clear();
  bridge.clear();
}
void doIt(){
  int t, n, m, k, a, b;
  scanf("%d", &t);
  rep(i, 0, t){
	init();
	scanf("%d%d%d", &n, &m, &k);
	rep(j, 0, m){
	  scanf("%d%d", &a, &b);
	  edge[a].push_back(b);
	  edge[b].push_back(a);
	}
	dfs(0);
	cout << bridge.size()*k << endl;
  }
}

//code from CodeChef Kingdom Unity
//http://ww2.codechef.com/APRIL13/problems/KINGCON
int main() {
  doIt();
  return 0;
}
