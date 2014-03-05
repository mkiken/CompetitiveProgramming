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
//const ll weight[] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10,1e11,1e12,1e13};
//priority_queue< int, vector<int>, greater<int> > q;
#define MAX_N 100002

#define MAX_PRIMES 31624
bool bPrimes[MAX_PRIMES];
vector<int> primes;
map<int, int> pmap;

void makePrimes(){
  afill(bPrimes, true);
  bPrimes[0] = bPrimes[1] = false;
  rep(i, 2, MAX_PRIMES){
	if(bPrimes[i]){
      pmap[i] = primes.size();
	  primes.push_back(i);
	  for(int j = 2*i; j < MAX_PRIMES; j += i) bPrimes[j] = false;
	}
  }
}

/*
Dinic法（from 蟻本）
O(|E||V|^2)
しかし、実際は高速に動作
“ In networks with unit capacities, a much stronger time bound holds. Each blocking flow can be found in O(E) time, and it can be shown that the number of phases does not exceed O(E ^ {1 / 2}) and O(V ^ {2 / 3}). Thus the algorithm runs in O(min(V^{2/3}, E^{1/2})E) time. “
*/

const int MAX_V = 203500;
struct edge{int to, cap, rev;};

vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from,int to,int cap){
  // printf("edge = (%d, %d)\n", from, to);
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size()-1});
}

void bfs(int s){
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while(que.size()){
    int v = que.front(); que.pop();
    // printf("v = %d\n", v);
    for(int i = 0 ; i < G[v].size() ; i++){
      edge &e = G[v][i];
      if(e.cap > 0 && level[e.to] < 0 ){
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

int dfs(int v, int t, int f){
  if(v == t) return f;
  for(int &i = iter[v]; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(e.cap > 0 && level[v] < level[e.to]){
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow = 0;
  for(;;){
    bfs(s);
    if(level[t] < 0) return flow;
    memset(iter, 0, sizeof(iter));
    int f;
    while((f = dfs(s, t, INF)) > 0){
      flow += f;
    }
  }
}

void init(int n){
  for(int i = 0 ; i < n ; i++) G[i].clear();
}


// https://www.hackerrank.com/contests/july13/challenges/computer-game
void doIt(){
  int n, A[MAX_N], B[MAX_N], s, t;
  map<int, vector<int> > mmapA, mmapB;
  makePrimes();
  scanf("%d", &n);
  Rep(i, n) scanf("%d", &A[i]);
  Rep(i, n) scanf("%d", &B[i]);
  Rep(i, n){
    int e = A[i];
    // printf("|p| = %d\n", (int)primes.size());
    Rep(j, primes.size()){
      if(e < primes[j] * primes[j]) break;
      if(e % primes[j] == 0){
        add_edge(i, 2*n + j, 1);
        while(e % primes[j] == 0){
          e /= primes[j];
        }
      }
    }
    if(e != 1){
      if(e < MAX_PRIMES) add_edge(i, 2*n + pmap[e], 1);
      else{
        mmapA[e].pb(i);
      }
    }
  }
  Rep(i, n){
    int e = B[i];
    Rep(j, primes.size()){
      if(e < primes[j] * primes[j]) break;
      if(e % primes[j] == 0){
        add_edge(2*n + j, n + i, 1);
        while(e % primes[j] == 0){
          e /= primes[j];
        }
      }
    }
    if(e != 1){
      if(e < MAX_PRIMES) add_edge(2*n + pmap[e], n + i, 1);
      else mmapB[e].pb(i);
    }
  }
  s = 2*n + primes.size();
  t = s + 1;
  Rep(i, n) add_edge(s, i, 1);
  Rep(i, n) add_edge(i + n, t, 1);
  mrep(it, mmapA, int, vector<int>){
    int e = (*it).first;
    if(mmapB.count(e)){
      vector<int> vA = (*it).second;
      vector<int> vB = mmapB[e];
      Rep(i, vA.size()){
        Rep(j, vB.size()){
          add_edge(vA[i], n + vB[j], 1);
        }
      }
    }
  }
  ll ans = max_flow(s, t);
  printf("%lld\n", ans);
}

int main() {
  doIt();
  return 0;
}
