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
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-10;
//const int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
//const int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//const int weight[] = {0,1,10,100,1000,10000,100000,1000000,10000000};
//priority_queue< int, vector<int>, greater<int> > q;
#define MAX_V 10001

//SCCを求める（蟻本）
int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v){
	used[v] = true;
	rep(i, 0, G[v].size()){
		if(!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v, int k){
	used[v] = true;
	cmp[v] = k;
	rep(i, 0, rG[v].size()){
		if(!used[rG[v][i]]) rdfs(rG[v][i], k);
	}
}
int scc(){
	afill(used, false);
	vs.clear();
	rep(v, 0, V){
		if(!used[v]) dfs(v);
	}
	afill(used, false);
	int k = 0;
	rrep(i, vs.size() - 1, 0){
		if(!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

// http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ACAC001&pid=D
void doIt(){
	int e, s, t, q;
	cin >> V >> e;
	rep(i, 0, e){
		cin >> s >> t;
		add_edge(s, t);
	}
	scc();
	cin >> q;
	rep(i, 0, q){
		cin >> s >> t;
		if(cmp[s] == cmp[t]) cout << 1 << endl;
		else cout << 0 << endl;
	}
}

int main() {
  doIt();
  return 0;
}
