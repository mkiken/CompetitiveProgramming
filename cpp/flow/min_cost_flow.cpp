#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

const ll INF = LLONG_MAX;
// const int MOD = (int)1e9 + 7;
// const double EPS = 1e-10;
#define PI acosl(-1)
#define MAX_N 100 + 2

/**
 * 最小費用流
 */
class MinCostFlow{
  struct edge{
    int to, cap, cost, rev;
  };
  
protected:
  static const int MAX_V = 1000 + 5;
  int V; // 頂点数
  vector<edge> G[MAX_V]; // グラフの隣接リスト表現
  ll dist[MAX_V]; // 最短距離
  int prevV[MAX_V], prevE[MAX_V]; // 直前の頂点と辺
  
public:
  MinCostFlow(){}
  MinCostFlow(int v){
    assert(v <= MAX_V);
    V = v;
  }
  void addEdge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
  }
  
  // sからtへの最小費用流を求める
  int exec(int s, int t, int f){
    int res = 0;
    
    while (f > 0){
      // ベルマンフォード法により、s-t間の最短経路を求める
      fill(dist, dist + V, INF);
      dist[s] = 0;
      bool update = true;
      while(update){
        update = false;
        for (int v = 0; v < V; v++){
          if (dist[v] == INF){
            continue;
          }
          
          for (int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost){
              dist[e.to] = dist[v] + e.cost;
              prevV[e.to] = v;
              prevE[e.to] = i;
              update = true;
            }
          }
          
        }
      }
      
      if (dist[t] == INF){
        // これ以上流せない
        return -1;
      }
      
      // s-t間最短路に沿って目一杯流す
      int d = f;
      for (int v = t; v != s; v = prevV[v]){
        d = min(d, G[prevV[v]][prevE[v]].cap);
      }
      f -= d;
      res += d * dist[t];
      for (int v = t; v != s; v = prevV[v]){
        edge &e = G[prevV[v]][prevE[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
void exec(){
  int V, E, F, u, v, c, d;
  cin >> V >> E >> F;
  
  MinCostFlow mcf = MinCostFlow(V);
  
  for (int i = 0; i < E; i++){
    scanf("%d%d%d%d", &u, &v, &c, &d);
    mcf.addEdge(u, v, c, d);
  }
  
  cout << mcf.exec(0, V-1, F) << endl;

}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
